import styled from "styled-components";
import { useQueueDispatch } from "../../context/QueueHooks";
import ImageCard from "./ImageCard";

const Layout = styled.div`
  min-height: 100vh;
  display: flex;
  justify-content: center;
  align-items: center;
  background-image: url("/src/images/background.jpg");
`;

const Wrapper = styled.div`
  max-width: 90%;
  display: flex;
  flex-direction: row;
  overflow-x: scroll;
  scrollbar-width: none;
  white-space: nowrap;
  background: var(--dark-gray);

  &::-webkit-scrollbar {
    display: none;
  }
  -ms-overflow-style: none;
  scrollbar-width: none;
`;

const Home = () => {
  const queueDispatch = useQueueDispatch();
  const inQueue = () => {
    queueDispatch({type:"INQUEUE"});
  }
	return (
		<Layout>
			<Wrapper>
        <ImageCard text={"Private"} imagePath={"/images/lock.png"} imagePadding="15px" routePath={"/matching"}/>
        <ImageCard text={"Public"} imagePath={"/images/earth.png"} imagePadding="25px" routePath={"/lobby"}/>
        <ImageCard text={"Arcade"} imagePath={"/images/controller.png"} imagePadding="15px" routePath={"/matching"}/>
        <ImageCard text={"Ladder"} imagePath={"/images/trophy.png"} imagePadding="15px"
        onclickhandler={inQueue}/>
        <ImageCard text={"Social"} imagePath={"/images/chat.png"} imagePadding="20px" routePath={"/social"}/>
			</Wrapper>
		</Layout>
	)
}

export default Home;
