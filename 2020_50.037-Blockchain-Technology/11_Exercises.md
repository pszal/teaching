##  More DApps

### Question 1

Using Python, Web3py, Web3js, Metamask, and Flask, develop a (DApp) web
application able to manage the coin tossing service created previously. It
should:
* Compile and deploy smart contract(s) automatically
* Interact with the contract when required; for example, get winner status or
  trigger an arbitrage
* Trigger interactions manually from a web GUI
* Users can interact through the web app using Metamask

**See an example below.**

### Question 2

Let's launch a crowdsale for your coin tossing service.  To do so, you make use
of an Initial Coin Offering (ICO), implemented via the ERC20 token standard.

```
+--------------+--------------------------------------------------------------+
| Start time   | 14-05-2020                                                   |
+-----------------------------------------------------------------------------+
| End time     | 20-05-2020                                                   |
+-----------------------------------------------------------------------------+
| Symbol token | MLC                                                          |
+-----------------------------------------------------------------------------+
| Total supply | 1 Million of MLC                                             |
+-----------------------------------------------------------------------------+
```

Some information about ERC20 tokens you can find at:
* https://github.com/ethereum/EIPs/blob/7f4f0377730f5fc266824084188cc17cf246932e/EIPS/eip-20.md 
* https://web3py.readthedocs.io/en/stable/examples.html#working-with-an-erc20-token-contract

### Warm-up: Python3 + Flask + Web3 + Metamask basic example

The *11_src/webapp* folder provides a simple DApp example that interacts with a
smart contract deployed in Ganache. Please analyze, study, and run this Dapp.
Make sure Metamask is connected properly and using an existing account.

```console
$ pip3 install py-solc flask web3
$ python3 -m solc.install v0.4.25
$ export PATH=$HOME/.py-solc/solc-v0.4.25/bin:$PATH
$ python3 server.py
```

**Screenshot:**
![alt](./11_src/before.png)

![alt](./11_src/after.png)
