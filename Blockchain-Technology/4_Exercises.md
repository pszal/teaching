## Week 4: SUTDcoin Network Protocol

### Question 1
Design and implement an `SPVClient` class.  SPV clients should implement a
simple SPV logic, i.e., they should:
- have their key pairs associated
- be able to receive block headers (not full blocks)
- be able to receive transactions (with their presence proofs) and verify them
- be able to send transactions

Integrate your implementation with your simulator from the previous exercise.
Test your implementation.


### Question 2
Move actors of your protocol (i.e., miners and SPV clients) to stand-alone
applications.  For their communication, design and implement a simple network
protocol.  Your protocol should be able to handle different kind of messages
(e.g., SPV clients need only headers, miners need to synchronize entire
blocks, ...).

To implement the network protocol you can use your favorite tools (e.g., the
HTTP protocol and Flask).  You can simplify some functionalities (but ask
before) like node discovery (e.g., a file with participants' addresses is good
enough).
