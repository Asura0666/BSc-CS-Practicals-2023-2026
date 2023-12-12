import React from "react";

const Box = ({value, handleClick, winner}) => {
  return (
    <div onClick={handleClick} className={`w-10 h-10 shadow-sm shadow-cyan-500 flex justify-center items-center font-bold text-xl ${winner? 'square-winner': ''}`}>
      {value}
    </div>
  );
};

export default Box;
