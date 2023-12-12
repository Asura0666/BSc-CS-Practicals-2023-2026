import React, { useMemo, useReducer } from "react";
import Box from "./Box";

const initialstate = {
  xIsNext: true,
  squares: Array(9).fill(null),
  winner: null,
};
const reducer = (state, action) => {
  switch (action.type) {
    case "RESET":
      return initialstate;
    case "CLICK":
      if (
        state.winner ||
        state.squares[action.payload] ||
        isBoardFull(state.squares)
      ) {
        return state;
      }
      const nextSquare = state.squares.slice();
      nextSquare[action.payload] = state.xIsNext ? "X" : "O";
      const winner = calculateWinner(nextSquare);
      return {
        ...state,
        squares: nextSquare,
        xIsNext: !state.xIsNext,
        winner: winner,
      };
    default:
      break;
  }
};
const isBoardFull = (squares) => {
  return squares.every((Square) => Square !== null);
};
const calculateWinner = (squares) => {
  const lines = [
    [0, 1, 2],
    [3, 4, 5],
    [6, 7, 8],
    [0, 3, 6],
    [1, 4, 7],
    [2, 5, 8],
    [0, 4, 8],
    [2, 4, 6],
  ];

  for (const [a, b, c] of lines) {
    if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) {
      return squares[a];
    }
  }
  return null;
};
const Board = () => {
  const [state, dispatch] = useReducer(reducer, initialstate);

  const handleClick = (i) => {
    dispatch({
      type: "CLICK",
      payload: i,
    });
  };

  const handleReset = () => {
    dispatch({ type: "RESET" });
  };

  const status = useMemo(() => {
    if (state.winner) {
      return `Winner: ${state.winner}`;
    } else if (isBoardFull(state.squares)) {
      return `It's a Draw`;
    } else {
      return `Next Player: ${state.xIsNext ? "X" : "O"}`;
    }
  });

  return (
    <div className="">
      <div className="flex justify-center flex-col items-center">
        <div className="text-xl">
          <span className="text-cyan-500 font-bold ">Tic</span>
          <span className="text-white font-bold ">-Tac-</span>
          <span className="text-cyan-500 font-bold ">Toe</span>{" "}
          <span className="text-red-500 font-bold ">Game</span>
        </div>
        <div className="text-lg my-8 font-bold">{status}</div>
        <div className="grid grid-rows-3 gap-4">
          {[0, 1, 2].map((row) => (
            <div key={row} className="grid grid-cols-3 gap-4">
              {[0, 1, 2].map((col) => (
                <Box
                  key={col}
                  value={state.squares[row * 3 + col]}
                  handleClick={() => handleClick(row * 3 + col)}
                  winner = {state.winner}
                />
              ))}
            </div>
          ))}
        </div>
        <button
          onClick={handleReset}
          className={`rounded-lg w-20 h-10 shadow-sm shadow-cyan-500 my-8 ${
            state.winner || isBoardFull(state.squares) ? "bg-red-500" : ""
          }`}
        >
          Reset
        </button>
      </div>
    </div>
  );
};
export default Board;
