## Week 8: Working with Bitcoin Testnet

In this session, we are going to interact with Bitcoin network.
To approach this exercises, we will use the following software:
* Electrum - Wallet for Bitcoin

**Note:** All required software is already installed in the provided virtual machine
image.

### Question 1

Using Electrum, create a Bitcoin account and get some coins.

Understanding:
* Why do we need a seed to create an account? How does that seed look like?
* What it means "Confirmations" when you receive and send coins?
* How do transactions look like? What is an input? What is an output?
* Is the total amount of coins transacted in a transaction the same amount that
you receive? Why? What is an input? What is an output?

**Note:** Make sure you are using Testnet network.

### Question 2

Using a Bitcoin Testnet blockchain explorer, find information about the
transaction with ID: **9bd15483ff8bdeaabdbd4224f060684e3449d2cbaaef4854effbfcebf80ff87e**

* What is the total amount transacted?
* What are receiving addresses?
* When did it happen?
* Now check transaction ID **27eb699a9ab24876858bd29c42f3831f036a57c72a3dc701c187d196291afbc8**, is it different?

**Note:** Suggested explorer https://www.blocktrail.com/tBTC

### Question 3

Create a multi signature account using all your group mates and adding the
following master public key as a co-signer (minimum 3 public keys in total).
Get and spend coins with this new account.

**co-signer public key:** tpubD6NzVbkrYhZ4X8DnNLNhBcvvZZE5W1MprBwEkD3mf2aUGXeTdSGxtRXuJntP4eEmbdV8uojLHYSntZgmxJXRuvZA8bjdvx8hFwmHXffyxfg

* What is the difference of using this type of accounts?
* What is required to use coins contained in such accounts?

### Question 4

For the following Bitcoin script, draw stages of the stack and determine the
outcome (true or false).

* OP_5 OP_1 OP_AND OP_HASH160 628850cb844fe63c308c62afc8bc5351f1952a7f OP_EQUAL
