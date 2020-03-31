## Smart Contract Vulnerabilities

Read and understand the following smart contracts. Find, exploit, and fix
their vulnerabilities.

**Note:** The smart contracts must be compiled using solidity v0.4.10.


### Question 1 (1pt)
```
pragma solidity ^0.4.10;

contract Bank {

    uint fees;
    address banker;

    mapping(address => uint) balances;

    function Bank(uint initialFees) {
        fees = initialFees;
        banker = msg.sender;
    }

    function changeFee(uint newFees) {
        fees = newFees;
    }

    function deposit() payable {
        balances[msg.sender] = balances[msg.sender] + msg.value;
    }

    function withdraw(uint amount) {
        uint newBalance = balances[msg.sender] - amount - fees;
        require(newBalance >= 0);
        balances[msg.sender] = newBalance;
        require(msg.sender.call.value(amount)());
    }

}
```


### Question 2 (1pt)
```
pragma solidity ^0.4.10;

contract Auction {
    
    address winner;
    uint lastBid;
    
    function Auction() public {
        winner = msg.sender;
        lastBid = 0;
    }

    function bid() public payable {
        assert(msg.value > lastBid);
        if (lastBid > 0) {
            assert(winner.call.value(lastBid)());
        }
        winner = msg.sender;
        lastBid = msg.value;
    }
    
    function getWinner() public returns(address) {
        return winner;
    }
    
}
```


### Question 3 (2pt)
```
pragma solidity ^0.4.10;

contract Bank {

    mapping(address => uint) balances;

    function deposit() public payable {
        balances[msg.sender] = balances[msg.sender] + msg.value;
    }

    function withdrawAll() public {
        uint amount = balances[msg.sender];
        assert(msg.sender.call.value(amount)());
        balances[msg.sender] = 0;
    }
    
    function getBalance(address _address) public returns(uint) {
        return(balances[_address]);
    }

}
```
