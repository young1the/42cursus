import { useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";
import styled from "styled-components";
import { useQueueDispatch } from "../../context/QueueHooks";
import SplaButton from "../SplaButton";
import { BackDrop, ModalProps } from "./ModalUtils";

const Box = styled.div`
  width: 24rem;
  height: 16rem;
  padding: 3rem;
  background: var(--white);
  color: var(--dark-gray);
  border-radius: 2rem;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  & > * {
    background: transparent;
  }
  gap: 2rem;
`;

const Title = styled.div`
  font-size: 1.5rem;
  text-align: center;
  font-family: NanumSquareL;
  margin-top: 1rem;
`;

const ButtonContainer = styled.div`
  display: flex;
  gap: 1rem;
`

const MatchingModal = ({ modalHandler }: ModalProps) => {
  const [count, setCount] = useState(10);
  const navigator = useNavigate();
  useEffect(() => {
    const timer = setInterval(() => {
      setCount((prev) => prev - 1);
    }, 1000);
    return () => {
      clearInterval(timer);
    };
  }, []);
  useEffect(() => {
    if (count === -1) {
      console.log("count zero");
      modalHandler();
    }
  }, [count]);
  const buttonHandler = () => {
    navigator("/game");
  };
  return (
    <BackDrop modalHandler={modalHandler}>
      <Box>
        <Title>매칭되었습니다!</Title>
        {count}
        <ButtonContainer>
        <SplaButton text="수락" onClickHandler={buttonHandler} />
        <SplaButton text="거절" onClickHandler={modalHandler} />
        </ButtonContainer>
      </Box>
    </BackDrop>
  );
};

export default MatchingModal;
