## Week 3: SUTDcoin Blockchain Design v0.2

### Question 1
Design and implement a `Miner` class realizing miner's functionalities.  Then,
implement a simple simulator with miners running Nakamoto consensus and making
transactions:

- Adjust the `TARGET` (global and static) parameter, such that on average new
  blocks arrive every 2-5 seconds.
- A miner who found a new block should be rewarded with 100 SUTDcoins.
- Introduce random transactions, such that miners (with coins) sends
  transactions to other miners.
- Make sure that coins cannot be double-spent.
    - consider the `addr:balance` model and the UTXO model. What are pros and
      cons?
    - do you need to modify (why, if so) the transaction format introduced in the
      first week?  *Hint:* yes, you need.
- Extend the verification checks.
- Simulate miners competition.
