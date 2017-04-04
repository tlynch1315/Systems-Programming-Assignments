Reading 09
==========
PBUI GAVE AN EXTENSION TO PEOPLE DOING A HACKATHON 
ACTIVITY ONE
==============
1)  s: 16 bytes
    u: 8 bytes(size of largest member)

2)  A union has multiple variables that are all stored in the same memory location, so you can only use one of the variables at a time.  In a struct each variable has its own memory location.

ACTIVITY TWO
==============
1) fate is inexorable!

2) te values set are the binary equivalent of the message being output, and since the varibales being set are in unions, the most reset value for each v value will be used.  

3) This program tells me that all of the memory is stored in binary and the types just determine how the binary is represented.  Memory is always represented by binary and the type determined the length of the binary number, but the values determine the values of the binary numbers.

ACTIVITY THREE
================
1) a collision is when two separate inputs give the same output in a hash table

2) hash tables that use separate chaining handle this by creating an array full of linked lists, so that each bucket in the array contains its own list of elements. This prevents two keys in the map having the same value.

3) this is handled by having the entried entered into an array and when a new entry is inserted the buckets are examined and if there is a collision, then the new entry is placed according the the algorithm for open addressing hash tables: (i+1) mod t.length(t is array) and if this doesn't work, it continues trying and increasing (i+1) but +1 every time

ACTIVITY FOUR
===============
1)  

BUCKET      VALUE
0
1
2           2, 72
3           3,13
4           14
5
6           56
7           7
8           78,68
9           79

2)
BUCKET      VALUE
0           68
1           14
2           2
3           3
4           72
5           13
6           56
7           7
8           78
9           79





