## Ethereum DApp - Back-end

### Question 1

Using Ganache [1] and Web3py [2] do the following:

* connect Web3py to Ganache
* make transactions between Ganache accounts
* get information (`number`, `gasLimit`, `gasUsed`, ...) of the latest block
* get and print a receipt of a conducted transaction

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

contract Fib {

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


[1] https://truffleframework.com/ganache <br />
[2] https://web3py.readthedocs.io/en/stable <br />
[3] https://solidity.readthedocs.io/en/v0.4.25/installing-solidity.html#solcjs <br />
[4] https://github.com/ethereum/py-solc <br />


### Cheatsheet: Minimum working example of contract deployment

Preliminaries:
```console
(install Ganache)
$ pip3 install py-solc web3
$ python3 -m solc.install v0.4.25
$ export PATH=$HOME/.py-solc/solc-v0.4.25/bin:$PATH
```

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

print('Calling contract functions')
print('Contract address: ', example.address)
print('obj.getOwner(): ', example.functions.getOwner().call())
```
