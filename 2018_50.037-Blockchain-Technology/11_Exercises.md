## Week 11: Ethereum Dapp - Back-end

### Question 1

Using Ganache [1] and Web3py [2] do the following:

* connect Web3py to Ganache
* make transactions between ganache accounts
* get information (`number`, `gasLimit`, `gasUsed`, ...) of the latest block
* get and print a receipt of a conducted transaction
* make transactions using currency conversions (e.g., Eth to Wei)

### Question 2

Using Ganache, Web3py, and a Solidity compiler [3, 4], compile and deploy the
smart contract below, and:

* execute available functions (notice the different between the `call()` and
  `transact()` methods)
* which Fibonacci function is more efficient? (in terms of gas cost)
* would `fibonacciA` be cheaper if it is non-payable?
* optimize `fibonacciB`

```js
pragma solidity ^0.4.25;

contract Week11 {

    uint constant FEE = 1 ether;

    address private owner;
    uint private previousFirst;
    uint private previousSecond;
    uint private next;

    constructor() public {
        owner = msg.sender;
    }

    function getOwner() public view returns(address) {
        return(owner);
    }

    function fibonacciA(uint n) public payable returns(uint) {
        require(msg.value == FEE, "You must pay to execute this");
        if(n == 0){return(0);}
        if(n == 1){return(1);}
        else{return(fibonacciA(n - 1) + fibonacciA(n - 2));}
    }

    function fibonacciB(uint n) public returns(uint) {
        previousFirst = 0;
        previousSecond = 1;
        next = 1;
        for(uint i = 2; i <= n; i++) {
            next = previousFirst + previousSecond;
            previousFirst = previousSecond;
            previousSecond = next;
        }
        return(next);
    }

}
```

### Question 3
Implement a simple mixing service that consists of
- an operator (i.e., app) that receives `from:to` address pairs,
- a smart contract that collects contributions, makes sure that amounts (chunks)
  are equal, and when triggered by the operator makes payments (see below).

After receiving *N* payments (let's assume *N=5*) the operator makes payments
using the stored `from:to` pairs.
The requirements of the system is an adversary observing the blockchain should be able to link `from`
and `to` addresses from a given pair with the *1/N* probability.

Do you see any problems with that service? Hint: consider a) order of payments,
b) adversarial race conditions. Fix these issues.



[1] https://truffleframework.com/ganache <br />
[2] https://web3py.readthedocs.io/en/stable <br />
[3] https://solidity.readthedocs.io/en/v0.4.25/installing-solidity.html#solcjs <br />
[4] https://github.com/ethereum/py-solc <br />


### Cheatsheet: Minimum working example of contract deployment

Example smart contract:
```js
pragma solidity ^0.4.25;

contract Example {

    address private owner;

    constructor() public {
        owner = msg.sender;
    }

    function getOwner() public view returns(address) {
        return(owner);
    }

}
```

Code to deploy and use it:
```python
'''
Once Ganache is installed, run its GUI or execute the following command:
$ ganache-cli -p 8545 -h 0.0.0.0 -n
'''

from solc import compile_source
from web3.auto import w3

contract_source_code = None
contract_source_code_file = 'example.sol'

with open(contract_source_code_file, 'r') as file:
    contract_source_code = file.read()

# Compile the contract
contract_compiled = compile_source(contract_source_code)
contract_interface = contract_compiled['<stdin>:Example']

# Set the default account
w3.eth.defaultAccount = w3.eth.accounts[0]

# Contract abstraction
Example = w3.eth.contract(abi=contract_interface['abi'], bytecode=contract_interface['bin'])

# Create an instance, i.e., deploy on the blockchain
tx_hash = Example.constructor().transact()
tx_receipt = w3.eth.waitForTransactionReceipt(tx_hash)

# Contract Object
example = w3.eth.contract(address=tx_receipt.contractAddress, abi=contract_interface['abi'])

print('Calling contracts functions')
print('Contract address: ', example.address)
print('obj.getOwner(): ', example.functions.getOwner().call())
```
