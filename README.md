# Midterm 2 Practice
For Oregon State's CS 261 (Data Structures) **section 010, Winter 2024**.

## Usage
All functions that Professor Todorovic indicated may be on the exam are declared in header files in the [`data_structures/`](./data_structures/) directory. The corresponding C source files contain a skeleton where you can practice writing the implementation for each function.

Any of the functions that is missing an implementation in [`data_structures/`](./data_structures/) may be on the exam. Struct definitions and helpful macros are defined in [`type.h`](./type.h). `COPY(a, b)` and `KEY_COPY(a, b)` are unlikely to be provided on the exam, but the practice problems make it appear that the exam will use simple datatypes (eg single character keys and integer values). I found it helpful to write an implementation for each of these functions and examine the test case output to ensure I correctly implemented each function, especially for the edge cases that carry the most weight on the exam.
> Note: If you think of test cases (especially edge cases) that I did not include in the test suite, please contact me over Slack, report an Issue, or submit a PR with the expanded test cases. All tests are organized by the data structure they test in the [`tests/`](./tests/) directory.

### Testing
When you are ready to test your implementation, [compile](#compiling) your code using the provided Makefile. This will generate an executable named `/exam_2`. Similar to the exam, when you run this executable, you will need to supply one command line argument for the number of elements you wish to test adding to the data structure(s). For example, you could run `./exam_2 5` to test adding 5 elements to the data structure(s). The Makefile has debugging symbols enabled for all compilation steps, so Valgrind should report the exact line number responsible for any memory issues if you choose to use it.
> Note: The test script will reject negative command line inputs.

### Compiling
This repository includes a Makefile for testing your implementation of each of the data structures. However you use the Makefile, the generated executable will be `/exam_2`. You have three options for compiling:
1. `make`: Compile all **your** data structure implementations and the test cases.
2. `make <data_structure>`: Compile **your** implementation for the given data structure and the test cases specific for it. Valid `<data_structure>` options are:
    * `bag`
    * `bst`
    * `d_linked_list`
    * `deque`
    * `hash_table`
    * `queue`
    * `stack`
3. `make solutions`: Compile the solution files I provided to see them run.
You can also clear all object files and the executable file by running `make clean`.

## Installation
This project should be ready to go from the moment you clone it. Since the exam will occur on a CLI distribution of Linux, I would recommend cloning this repo from the command line on the College of Engineering servers and using `vim` or `nano` to practice for the exam. This is a simple process. First, open the Terminal on Mac/ Linux or MobaXterm on Windows. Then, run the following commands:
```bash
# {ONID} should be replaced with your ONID, eg smithj.
ssh {ONID}@access.engr.oregonstate.edu      

# If you have not connected to the CoE servers over SSH before, you will be asked if you 
# trust the server. Type "yes" and press enter.

# If you have not set up SSH keys, you will need to enter your password
# and enter `1` for a Duo Push.

# You should see a confirmation that you logged in, and the bottom line should start with 
# "flipX ~ " (1 ≤ X ≤ 4).



# `cd` into a CS 261 directory if you have one. If not, don't worry about it.

# Next we'll make a copy of this repository on the CoE server.
git clone https://github.com/radiantBear/CS261-midterm-2.git
cd CS261-midterm-2



# Everything you need to implement is in the data_structures/ directory, so we'll go there.
cd data_structures

# Use vim or nano to fill in the empty functions in all the C source files.
# (To return to the command line from vim, press [esc] and type ":wq")
vim bag.c



# Test your code as outlined above
make bag
valgrind ./exam_2 5

# If the make command ever fails to sync your changes, you can remove all object and 
# executable files and try again
make clean
```

## Test Results
```
--------------------- Testing doubly-linked list ----------------------

Initial doubly-linked list:
Data (front to back): 0, 2, 0, 0, 3, 1, 3, 1, 1, 1
Data (back to front): 1, 1, 1, 3, 1, 3, 0, 0, 2, 0

Adding to doubly-linked list front: 
Data (front to back): 1, 0, 2, 0, 0, 3, 1, 3, 1, 1, 1
Data (back to front): 1, 1, 1, 3, 1, 3, 0, 0, 2, 0, 1

Adding to doubly-linked list back: 
Data (front to back): 1, 0, 2, 0, 0, 3, 1, 3, 1, 1, 1, 3
Data (back to front): 3, 1, 1, 1, 3, 1, 3, 0, 0, 2, 0, 1

Removing from doubly-linked list back: 
Data (front to back): 1, 0, 2, 0, 0, 3, 1, 3, 1, 1, 1
Data (back to front): 1, 1, 1, 3, 1, 3, 0, 0, 2, 0, 1

Removing from doubly-linked list front: 
Data (front to back): 0, 2, 0, 0, 3, 1, 3, 1, 1, 1
Data (back to front): 1, 1, 1, 3, 1, 3, 0, 0, 2, 0

Removing everything from doubly-linked list:
Data (front to back): 
Data (back to front): 

Removing front sentinel: 
Data (front to back): 
Data (back to front): 

Removing back sentinel: 
Data (front to back): 
Data (back to front): 

Adding before front sentinel: 
Data (front to back): 
Data (back to front): 

Adding to doubly-linked list: 
Data (front to back): 0
Data (back to front): 0

----------------------------- Testing bag -----------------------------

Initial bag:
Data (front to back): 3, 4, 2, 0, 0, 4, 4, 4, 3, 2
Data (back to front): 2, 3, 4, 4, 4, 0, 0, 2, 4, 3

Bag contains 0: true
Bag contains 1: false
Bag contains 2: true
Bag contains 3: true
Bag contains 4: true
Bag contains 5: false

Removing first element by value:
Data (front to back): 4, 2, 0, 0, 4, 4, 4, 3, 2
Data (back to front): 2, 3, 4, 4, 4, 0, 0, 2, 4

Removing all elements with same value:
Data (front to back): 4, 2, 0, 0, 4, 4, 4, 2
Data (back to front): 2, 4, 4, 4, 0, 0, 2, 4

Removing an element with value not in bag:
Data (front to back): 4, 2, 0, 0, 4, 4, 4, 2
Data (back to front): 2, 4, 4, 4, 0, 0, 2, 4

Removing all elements with value not in bag:
Data (front to back): 4, 2, 0, 0, 4, 4, 4, 2
Data (back to front): 2, 4, 4, 4, 0, 0, 2, 4

Removing all values from bag:
Data (front to back): 
Data (back to front): 

Removing a value from an empty bag:
Data (front to back): 
Data (back to front): 

Added to bag again: 
Data (front to back): 4
Data (back to front): 4

---------------------------- Testing stack ----------------------------
Initial stack:
Data (front to back): 1, 1, 0, 3, 3, 3, 3, 0, 0, 3
Data (back to front): 3, 0, 0, 3, 3, 3, 3, 0, 1, 1

Pushed onto stack: 
Data (front to back): 0, 1, 1, 0, 3, 3, 3, 3, 0, 0, 3
Data (back to front): 3, 0, 0, 3, 3, 3, 3, 0, 1, 1, 0

Stack after popping: 
Data (front to back): 1, 1, 0, 3, 3, 3, 3, 0, 0, 3
Data (back to front): 3, 0, 0, 3, 3, 3, 3, 0, 1, 1

Stack after popping everything: 
Data (front to back): 3
Data (back to front): 3

Popped from empty stack: 
Data (front to back): 
Data (back to front): 

Pushed onto stack again: 
Data (front to back): 2
Data (back to front): 2

---------------------------- Testing queue ----------------------------

Initial queue:
Data (front to back): 2, 4, 0, 0, 0, 3, 1, 2, 1, 1
Data (back to front): 1, 1, 2, 1, 3, 0, 0, 0, 4, 2

Adding to queue: 
Data (front to back): 2, 4, 0, 0, 0, 3, 1, 2, 1, 1, 1
Data (back to front): 1, 1, 1, 2, 1, 3, 0, 0, 0, 4, 2

Removing from queue: 
Data (front to back): 4, 0, 0, 0, 3, 1, 2, 1, 1, 1
Data (back to front): 1, 1, 1, 2, 1, 3, 0, 0, 0, 4

Removing everything from queue:
Data (front to back): 1
Data (back to front): 1

Removing from empty queue: 
Data (front to back): 
Data (back to front): 

Adding to queue: 
Data (front to back): 2
Data (back to front): 2

---------------------------- Testing deque ----------------------------

Initial deque:
Data (front to back): 3, 3, 3, 2, 2, 4, 4, 2, 0, 0
Data (back to front): 0, 0, 2, 4, 4, 2, 2, 3, 3, 3

Removing from deque front: 
Data (front to back): 3, 3, 2, 2, 4, 4, 2, 0, 0
Data (back to front): 0, 0, 2, 4, 4, 2, 2, 3, 3

Removing from deque back: 
Data (front to back): 3, 3, 2, 2, 4, 4, 2, 0
Data (back to front): 0, 2, 4, 4, 2, 2, 3, 3

Removing everything from deque:
Data (front to back): 
Data (back to front): 

Removing from empty deque front: 
Data (front to back): 
Data (back to front): 

Removing from empty deque back: 
Data (front to back): 
Data (back to front): 

Adding to deque front: 
Data (front to back): 2
Data (back to front): 2

Adding to deque back: 
Data (front to back): 2, 3
Data (back to front): 3, 2

------------------------- Testing hash table --------------------------

Initial hash table:
Elements in hash table: 10
Buckets in hash table: 5
Data (by bucket):
    0| "Juliette": 1
    1| "Delta": 2
    2| "Tango": 3, "Golf": 0, "Whiskey": 2
    3| "Romeo": 0, "Romeo": 2
    4| "Yankee": 1, "Quebec": 2, "Charlie": 2

Hash table contains Alpha: false
Hash table contains Charlie: true
Hash table contains Echo: false
Hash table contains Golf: true
Hash table contains India: false
Hash table contains Kilo: false
Hash table contains Mike: false
Hash table contains Oscar: false
Hash table contains Quebec: true
Hash table contains Sierra: false
Hash table contains Uniform: false
Hash table contains Whiskey: true
Hash table contains Yankee: true

Removing first element with key Juliette:
Elements in hash table: 9
Buckets in hash table: 5
Data (by bucket):
    0| 
    1| "Delta": 2
    2| "Tango": 3, "Golf": 0, "Whiskey": 2
    3| "Romeo": 0, "Romeo": 2
    4| "Yankee": 1, "Quebec": 2, "Charlie": 2

Removing all elements with key Juliette:
Elements in hash table: 9
Buckets in hash table: 5
Data (by bucket):
    0| 
    1| "Delta": 2
    2| "Tango": 3, "Golf": 0, "Whiskey": 2
    3| "Romeo": 0, "Romeo": 2
    4| "Yankee": 1, "Quebec": 2, "Charlie": 2

Removing an element with value not in hash table:
Elements in hash table: 9
Buckets in hash table: 5
Data (by bucket):
    0| 
    1| "Delta": 2
    2| "Tango": 3, "Golf": 0, "Whiskey": 2
    3| "Romeo": 0, "Romeo": 2
    4| "Yankee": 1, "Quebec": 2, "Charlie": 2

Removing all elements with value not in hash table:
Elements in hash table: 9
Buckets in hash table: 5
Data (by bucket):
    0| 
    1| "Delta": 2
    2| "Tango": 3, "Golf": 0, "Whiskey": 2
    3| "Romeo": 0, "Romeo": 2
    4| "Yankee": 1, "Quebec": 2, "Charlie": 2

Removing all values from hash table:
Elements in hash table: 0
Buckets in hash table: 5
Data (by bucket):
    0| 
    1| 
    2| 
    3| 
    4| 

Removing a value from an empty hash table:
Elements in hash table: 0
Buckets in hash table: 5
Data (by bucket):
    0| 
    1| 
    2| 
    3| 
    4| 

Added to hash table again: 
Elements in hash table: 1
Buckets in hash table: 5
Data (by bucket):
    0| 
    1| 
    2| "Whiskey": 0
    3| 
    4| 

--------------------- Testing binary search tree ----------------------

Initial tree:
Nodes in binary search tree: 10
─── 0
    ├── 
    └── 0
        ├── 
        └── 4
            ├── 1
            │   ├── 
            │   └── 3
            │       ├── 1
            │       │   ├── 
            │       │   └── 1
            │       │       ├── 
            │       │       └── 2
            │       └── 3
            └── 4

Preorder tree traversal: 0 0 4 1 3 1 1 2 3 4 
Inorder tree traversal: 0 0 1 1 1 2 3 3 4 4 
Postorder tree traversal: 2 1 1 3 3 1 4 4 0 0 
Depth-first tree traversal: 2 1 1 3 3 1 4 4 0 0 
Top-down tree traversal: 

BST contains 0: true
BST contains 1: true
BST contains 2: true
BST contains 3: true
BST contains 4: true
BST contains 5: false

Adding to tree: 
Nodes in binary search tree: 11
─── 0
    ├── 
    └── 0
        ├── 
        └── 4
            ├── 1
            │   ├── 
            │   └── 3
            │       ├── 1
            │       │   ├── 
            │       │   └── 1
            │       │       ├── 
            │       │       └── 2
            │       └── 3
            │           ├── 
            │           └── 3
            └── 4

Testing internal contains function:
BST contains 0: true
BST contains 1: true
BST contains 2: true
BST contains 3: true
BST contains 4: true
BST contains 5: false

Testing internal add function:
Nodes in binary search tree: 12
─── 0
    ├── 
    └── 0
        ├── 
        └── 4
            ├── 1
            │   ├── 
            │   └── 3
            │       ├── 1
            │       │   ├── 
            │       │   └── 1
            │       │       ├── 
            │       │       └── 2
            │       └── 3
            │           ├── 
            │           └── 3
            │               ├── 
            │               └── 3
            └── 4
```