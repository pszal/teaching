pragma solidity ^0.4.24;

contract Lottery {

    address private owner;
    uint private number;


    constructor() public {
        owner = msg.sender;
    }

    function setNumber(uint _number) public {
        number = _number;
    }

    function getNumber() view public returns(uint) {
        return(number);
    }

    function getOwner() view public returns(address){
        return(owner);
    }

}
