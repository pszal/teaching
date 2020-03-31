## Working with Remix, Solidity, and Ethereum

* Get basic knowledge of Solidity: https://solidity.readthedocs.io/
* Get familiar with Remix: https://remix.ethereum.org/
* You may need to use some wallet to interact, e.g., Metamask

### Question 1

Design, implement, and deploy (can be locally) a two-party coin tossing protocol
and a smart contract running it.

* For two participating users, Alice and Bob, your smart contract should
determine the winner.
* The protocol must be *fair*, i.e., for every run, Alice and Bob have equal 50%
  probability of winning.
* The protocol must be *secure*, i.e., whenever a party deviates from the
  protocol it should be punished (e.g., by a deposit loss).


### Question 2

Using your application, explore and demonstrate the following Solidity features.

* Explore different data types
* Make use of struct types and mappings
* Create payable functions
* Define modifiers
* Implement inheritance from an existing deployed smart contract
* Play with functions visibility and understand their differences
* How is it possible to integrate a log?
* Is it possible to create an infinite loop?
* Calls between smart contracts
* Create a fallback function, how it works?
