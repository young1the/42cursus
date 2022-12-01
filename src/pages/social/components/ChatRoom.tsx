import styled from "styled-components";
import SectionHeader from "../../../components/SectionHeader";
import ChatInput from "./ChatInput";
import ChatCard from "./ChatCard";
import { useEffect, useRef, useState } from "react";

const Container = styled.div`
  position: relative;
  width: 100%;
  height: 100%;
  display: flex;
  flex-direction: column;
  background: var(--dark-gray);
`;

const ChatSection = styled.div`
  width: 100%;
  height: 100%;
  overflow: auto;
  &::-webkit-scrollbar {
    width: 0.5rem;
  }
  &::-webkit-scrollbar-thumb {
    background-color: var(--yellow);
    border-radius: 10px;
  }
  &::-webkit-scrollbar-track {
    background-color: rgba(0, 0, 0, 0);
  }
`;

const ChatContainer = styled.div`
  padding: 1rem;
  display: flex;
  flex-direction: column;
  justify-content: flex-end;
  background: var(--dark-gray);
`;

const InputSection = styled.div`
  display: flex;
  justify-content: space-between;
  width: 100%;
  padding: 1rem;
  gap: 0.5rem;
`;

export type Message = {
	nickname: string,
	intra_id: string,
  profile_url: string,
	time: string,
	chat: string,
};

const DummyMessages: Message[] = [
  {
    nickname: "other",
    intra_id: "other",
    profile_url: "/src/images/hero.png",
    time: "2022-11-11 11:11",
    chat: "테스트",
  },
  {
    nickname: "young-ch",
    intra_id: "young-ch",
    profile_url: "/src/images/hero.png",
    time: "2022-11-11 11:12",
    chat: "테스트",
  },
  {
    nickname: "young-ch",
    intra_id: "young-ch",
    profile_url: "/src/images/hero.png",
    time: "2022-11-11 11:12",
    chat: "테스트",
  },
  {
    nickname: "young-ch",
    intra_id: "young-ch",
    profile_url: "/src/images/hero.png",
    time: "2022-11-11 11:12",
    chat: "테스트",
  },
  {
    nickname: "other",
    intra_id: "other",
    profile_url: "/src/images/hero.png",
    time: "2022-11-11 11:13",
    chat: "테스트",
  },
  {
    nickname: "other",
    intra_id: "other",
    profile_url: "/src/images/hero.png",
    time: "2022-11-11 11:14",
    chat: "테스트",
  },
  {
    nickname: "other",
    intra_id: "other",
    profile_url: "/src/images/hero.png",
    time: "2022-11-11 11:14",
    chat: "테스트",
  },
];

const Chat = ({title, isInfoOn, setIsInfoOn, setData}: {title: string, isInfoOn: boolean, setIsInfoOn: any, setData: any}) => {
  const [userMessage, setUserMessage] = useState(null);
  const lastChat = useRef<HTMLDivElement>(null);

  useEffect(() => {
    lastChat?.current?.scrollIntoView({
      behavior: "smooth",
      block: "end",
      inline: "nearest",
    });
	if (userMessage)
		DummyMessages.push(userMessage);
    return setUserMessage(null);
  }, [userMessage]);

  return (
    <Container>
      <SectionHeader color="var(--purple)" title={title}>
        <div onClick={() => setIsInfoOn(true)}>{":"}</div>
      </SectionHeader>
      <ChatSection>
        <ChatContainer ref={lastChat}>
          {DummyMessages.map((item, idx) => {
            const { nickname: sender, time, chat } = item;
            const isMe = (sender == "young-ch") ? true : false;
            return (
              <ChatCard
                key={idx}
                isMe={isMe}
                message={item}
                setIsInfoOn={() => setIsInfoOn(true)}
                setData={setData}
              ></ChatCard>
            );
          })}
        </ChatContainer>
      </ChatSection>
      <InputSection>
        <ChatInput setUserMessage={setUserMessage}></ChatInput>
      </InputSection>
    </Container>
  );
};

export default Chat;
