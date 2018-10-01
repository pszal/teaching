## Week 1: Introduction and Warm-up

![alt](./sutdcoin.png)


Understanding that cryptocurrency have been the most visible application of
blockchain, we are going to design and implement a cryptocurrency during the
following 6 weeks. In that way, we are going to have the following schedule:

* Week1 - Basics of cryptocurrency, coding, encoding, Merkle trees
* Week2 - SUTDcoin blockchain – basic design and implementation, forks handling
* Week3 - SUTDcoin blockchain – PoW, mining, transactions, and SPV
* Week4 - SUTDcoin networking – propagation, discovery, mining competition,
  interactions
* Week5 - SUTDcoin attacks – double-spending and selfish-mining attacks
* Week6 - SUTDcoin – shaping up and early grading

To approach this, we are going to develop Python v3.6 using the packages:
base58, ecdsa, flask, hashlib, sqlite3, and matplotlib.

**Note:** You do not have to configure your personal computer. In the
[https://bit.ly/2Pjw2VE](https://bit.ly/2Pjw2VE), you can download a provided
virtual machine image for VirtualBox hypervisor which is a Linux OS that has all
packages and is configured already with necessary to perform the labs. However,
it requires minimum 2GB RAM, 20GB Disk, and 2 CPUs.

**General note:** All JSON examples are displayed in a manner to make them
readable, consider joining strings properly and using json.dump(data) before
any cryptography function.


### Question 1

Get the hash value of `"Blockchain Technology"` using SHA2-256, SHA2-512,
SHA3-256, and SHA3-512.

**Note:** throughout the rest of this course use SHA2-256 as the default hash
function.


### Question 2

Let us define a hash function `H(n, msg)` that computes SHA2-512 over `msg` and
outputs the first `n` bits of the hash.

- Find a collision of `H(8, msg)`, `H(16, msg)`, `H(24, msg)`, `H(32, msg)`, and
  `H(40, msg)`.  Measure how long it takes to find a collision.
- For `H(8, msg)`, `H(16, msg)`, `H(24, msg)`, `H(32, msg)` and `H(40, msg)`
  find a preimage of the corresponding hashes: `b"\x00"`, `b"\x00"*2`, `b"\x00"*3`,
  `b"\x00"*4`, and `b"\x00"*5`.  Measure how long it takes to find a preimage.
- Compare times of finding a collision and a preimage.


### Question 3

Generate key pairs for ECDSA and sign the string `"Blockchain Technology"`
using this signature scheme with the generated key. Then verify the obtained
signature.

**Note:** throughout the rest of this course use NIST192p as the default curve
for the ECDSA signature scheme (this one is used by default by the `ecdsa`
package, but in real applications a longer/more secure curve should be
considered).


### Question 4
Design and implement a `Transaction` class that includes the following fields

- sender (a public key of sender)
- receiver (a public key of receiver)
- amount (transaction amount, an integer >0)
- comment (arbitrary text, can be empty)
- signature (sender's signature protecting the transaction)

The class should provide the following interface

<pre>
class Transaction(...):
    ...

    @classmethod
    def new(...):
        # Instantiates object from passed values
        ...

    def to_json(...):
        # Serializes object to JSON string
        ...

    @classmethod
    def from_json(...):
        # Instantiates/Deserializes object from JSON string
        ...

    def sign(...):
        # Sign object with private key passed
        # That can be called within new()
        ...

    def validate(...):
        # Validate transaction correctness.
        # Can be called within from_json()
        ...

    def __eq__(...):
        # Check whether transactions are the same
        ...
</pre>
(**Note:** this interface, maybe w/o `sign()`, will be useful for other future
classes.)

Test your implementation.
- Do you think it makes sense to add any other fields?
- What checks are you going to include within `validate()` ?
- Do you see any challenges in implementing `sign()` and `verify()`?


### Question 5

Develop a full implementation of a Merkle tree.  Your implementation should
implement the following methods and functions
<pre>
class MerkleTree(...):
    ...

    def add(...):
        # Add entries to tree
        ...

    def build(...):
        # Build tree computing new root
        ...

    def get_proof(...):
        # Get membership proof for entry
        ...

     def get_root(...):
        # Return the current root
        ...

def verify_proof(entry, proof, root):
    # Verifies proof for entry and given root. Returns boolean.
    ...
</pre>

(Make sure you distinguish leaf nodes from non-leaf node.)

Populate the tree with a random number (between 100-1000) of random
transactions, compute a root, get proofs for 10 random entries and verify them.
