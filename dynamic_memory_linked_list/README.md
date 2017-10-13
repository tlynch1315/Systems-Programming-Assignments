Homework 07
===========

The goal of this homework assignment was to practice using dynamic memory in C. The first activity involved building a singly-linked list library, while the second activity required me to use this library to build and benchmark a lsort utility similar to sort.

ACTIVITY ONE
==============
1) in node_create I allocated memory for the size of a node, which includes enough memory for a string, int, and pointer to next node, then in the node_delete, I deallocated all of that memory, by doing free(n->string) and free(n).  I dealt with the recursive flag by using a while loop it iterates over the next nodes if the recursive flag was true.

2) In list_create I allocated enough memory for the sizeof a list, including a node for head, tail, and an int for size.  In the list_delete function I deallocated memory using node_delete(l->head, true), which recursively frees all of the nodes in the list, then free(l) freed the memory the list was using. I handled the internal nodes by making the node_delete recursive.

3) list_qsort takes the list, puts it into an array using list_to_array(), then uses the built in function qsort for arrays, and then reassigns the values to the list using the array. 
    average time complexity: O(nlog(n))
    worst case time complexity: O(n^2)
    constant space complexity

4) list_reverse works by using three pointers to keep track of the values, and uses reverse to reverse the first and last pointer, while keeping the middle one the same. then the first pointer is set to the value of the third one.
    average and worst time complexity: O(n)
    constant space complexity;

5) list_msort calls the msort function, then that calls the split function by passing two pointers by reference in order to split the list in half.  Then, while left != NULL, it keeps calling msort, which splits it.  The same process is done for the right side.  This process splits the list into individual nodes, then msort compares the values and places them into the correct order and the new head is then returned to list_msort.
    average and worst case time complexity: O(nlog(n))
    space complexity: O(log(n)) because msort is called recursively

ACTIVITY TWO
==============
1) Quick sort is always faster than merge sort, but it requires more space.  I expected mergesort to be faster and take up more space based on the time and space complexities.

2) Real world complexity is much more complex than theoretical complexity.  In theory, it just depends upon the code, but in practice it depends upon the hardware as well, so the big O notation is just a trend, not a guaranteed value.
