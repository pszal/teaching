## Week 8: Working with Bitcoin and Ethereum Testnets

In this session, we are going to interact with Bitcoin network.
To approach this exercises, we will use the following software:
* Electrum - Wallet for Bitcoin
* Mist/Metamask - Wallet for Ethereum

### Question 1

Using Electrum, create a Bitcoin account and get some coins.

Understanding:
* Why do we need a seed to create an account? How does that seed look like?
* What it means "Confirmations" when you receive and send coins?
* How do transactions look like? What is an input? What is an output?
* Is the total amount of coins transacted in a transaction the same amount that
you receive? Why? What is an input? What is an output?

**Note:** Make sure you are using a Testnet network.

### Question 2

Using a Bitcoin Testnet blockchain explorer (e.g., https://www.blockchain.com/),
find information about the transaction with ID:
**fee016da83f476083918d4f9c77acbb057df1563bec6b337adb249d5c7c40bc5**

* What is the total amount transacted?
* What is/are the receiving address(es)?
* What is the miner's fee?
* How the inputs were spent?
* Now check the transaction ID **27eb699a9ab24876858bd29c42f3831f036a57c72a3dc701c187d196291afbc8** and compare how these two transactions spent their inputs.

### Question 3

Using Mist/Metamask, create an Ethereum account, then get and spend some coins.

**Note:** Make sure you are using a Testnet network (e.g., Ropsten).

### Question 4

Using an Ethereum testnet blockchain explorer (e.g., https://ropsten.etherscan.io/), 
find information about the account with ID: **0xDE314df1A5241D38E9603d784b8A186E0543521E**

* What is the account's balance?
* When was the last transaction performed?
* Does it have any smart contract created?

### Question 5

In Bitcoin, we have an option of creating multisig transactions. How it can be
realized in Ethereum?

### Question 6

For the following Bitcoin script, draw stages of the stack and determine the
outcome (true or false).

* OP_4 OP_1 OP_AND OP_SHA256 e77b9a9ae9e30b0dbdb6f510a264ef9de781501d7b6b92ae89eb059c5ab743db OP_EQUAL
