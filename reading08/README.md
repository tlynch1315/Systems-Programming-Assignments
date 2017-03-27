Reading 08
==========
ACTIVITY ONE
==============
1.1) 4 bytes
1.2) 20 bytes
1.3) 8 bytes
1.4) 16 bytes
1.5) 8 bytes
1.6) 8 bytes
1.7) 8 bytes
1.8) 8 bytes

ACTIVITY TWO
===============
1) Memory error in tast 3 happened when the randoms is generated. originally it is
    int *randoms = malloc();    
    then,
    int *randoms = malloc(n*sizeof(int));

    this is needed because the memory allocation has to be the size of the memory, not just the number of ints passed in.

2) This leak happened when the memory for the randoms pointer was not freed.  This happened whenever true was returned, so the memory was not getting freed when there was no duplicate detected. I fixed this by putting: free(randoms); before the return true; statement.
