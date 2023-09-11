## Socket.io 기반 온라인 게임 서비스

### ⏰ 기간

---

2022.10.25 ~ 2022.12.13

### 👯‍♂️ 팀 구성

---

프론트엔드 3명, 백엔드 2명

### **🖥 시연**

---
![donegameplay_AdobeExpress](https://github.com/young1the/42cursus/assets/86599495/535c871b-dd39-418a-aec2-6912773052c6)


### **⚡️ 사용 기술**

---

- React
- TypeScript
- Styled Components
- Axios
- Docker-Compose

### 🏓 기능

---

### 1. 로그인

![login_AdobeExpress_AdobeExpress](https://github.com/young1the/42cursus/assets/86599495/3fe46a4d-d48d-429e-a22d-c54870626df8)

- 42 Intra의 OAuth를 이용하여 로그인합니다
- 2차 인증을 설정한 유저들은 추가로 이메일 인증 로그인을 할 수 있습니다.
- 닉네임, 프로필 사진을 변경할 수 있습니다.

### 2. 게임

![matching_player_AdobeExpress_AdobeExpress](https://github.com/young1the/42cursus/assets/86599495/be8677fc-bdce-4ee7-b43d-5e353f2f3bcf)

- 랜덤 매칭을 통해 무작위 상대와 대결할 수 있습니다.
- 매칭 대기 중에 채팅을 할 수 있습니다.
- 모든 게임 기록은 저장되어 프로필에서 확인할 수 있습니다.

### 3. 소셜

![addfriend_AdobeExpress_AdobeExpress](https://github.com/young1the/42cursus/assets/86599495/db601118-39ad-4153-95b0-d3f335ce0827)

- 친구를 추가하여 온라인 또는 오프라인 상태를 확인 할 수 있습니다.
- 친구에게 다이렉트 메세지를 보낼 수 있습니다.
- 공개 또는 비밀 채널을 생성하고 많은 사람들과 대화 할 수 있습니다.

### 💁‍♂️ 담당 부분

---

### 1. 레이아웃 및 주요 기능 설계

![C0410EB9-2AA1-421F-ADB6-92B0ABE521DF](https://github.com/young1the/42cursus/assets/86599495/1f4e7f69-d9bf-440c-b280-034dd4dbd8af)

![CF0AEA1A-19D4-4049-8EE0-DD5F691B04C8](https://github.com/young1the/42cursus/assets/86599495/288b498e-2d1b-4cf9-93d1-587924d62de0)

- 트센뽀개기였던 팀의 이름을 24(two-four)로 다시 지었습니다.
- 팀원들과 회의를 통해 기본적인 레이아웃을 구상하고, 구현할 기능들을 정리했습니다.

### 2. 지식공유

[context/README.md](https://github.com/young1the/42cursus/blob/master/ft_trancendence/24-front/src/context/README.md)

- React Context API를 구현하고 해당 내용을 팀원에게 사용법과 함께 공유했습니다.
- Socket.io 의 사용법을 팀원들에게 공유했습니다.
- UI 대부분을 구현하고 팀원들이 CSS 사용에 문제가 있을 때 해결해주었습니다.

### 3. Docker Compose 작성

```docker
# front-end Dockerfile
FROM node
WORKDIR /app/front
COPY package.json /app/front
COPY package-lock.json /app/front
RUN npm i
COPY . /app/front
EXPOSE 5173
CMD ["npm", "run", "dev"]
```

```yaml
# docker-compose.yaml
version: '3'
services:
  postgres:
    image: postgres
    restart: always
    environment:
      POSTGRES_USER: ${DATABASE_USERNAME}
      POSTGRES_PASSWORD: ${DATABASE_PASSWORD}
      POSTGRES_DB: ${DATABASE_DATABASE}
    ports:
      - 5432:5432
    networks:
      - 24-network
  back: 
    build: 
      context: "./24-back"
      dockerfile: Dockerfile 
    container_name: "back" 
    working_dir: "/app/back" 
    env_file:
      - .env
    ports: 
      - "3000:3000"
    depends_on:
      - postgres
    restart: always
    networks:
      - 24-network
  front: 
    build: 
      context: "./24-front"
      dockerfile: Dockerfile 
    container_name: "front" 
    working_dir: "/app/front" 
    env_file: .env
    depends_on:
      - back
    ports: 
      - "5173:5173"
    networks:
      - 24-network
networks:
  24-network:
```

다양한 환경에서 동일한 개발 환경을 제공하기 위해 Dockerfile 작성 및 docker-compose 파일 작성을 맡았습니다.

### 4. 문제해결

```tsx
useEffect(() => {
    const idx = location.search.indexOf("?token=");
    if (idx >= 0) {
      const token = location.search.slice(7);
      flushSync(() => dispatch({ type: "LOGIN", payload: token }));
      flushSync(() => navigate("/"), { replace: true });
    } else {
      navigate("/login", { replace: true });
    }
  }, []);
```

최초 로그인 시(회원가입), OAuth 인증 이후 profile 페이지로 리다이렉트 되도록, `<Init />` 컴포넌트를 구현했습니다.

간단하게 `<Navigate to={path}/>` 부분에서 path만 수정해주면 될 거라고 생각했는데, 잘 안되서 Auth 부분을 전부 고쳤습니다.

분명 코드상으로는,

1. useLocation을 사용해서 redirect url에서 token부분만 slice,
2. AuthContextDispatch로 AuthContext에 token 저장,
3. 프로필 페이지로 이동,

1->2->3 순서로 실행되야 하지만, 콘솔로그를 찍어보니, 1->3->`RequireAuth` 컴포넌트에서 토큰이 확인되지 않아 login페이지로 이동->2->`Restrict` 컴포넌트에서 토큰이 있는데 로그인 관련 페이지로 접속해서 메인 페이지로 이동됐습니다.

그래서 조금 찾아보니 react에서 상태변경은 동기적으로 일어나지 않아서 react18에 업데이트 된 `flushSync` 메서드를 사용해서 동기적으로 일어나야 하는 상태변경을 관리해줘야 한다고 합니다.
