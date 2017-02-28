Reading 06
==========
2
====
a) MapReduce aims to solve very large scale problems that are not too complicated.  It is most useful in multi-threaded implementations instead of single-threaded implementations because it does multiple things at once so using it for a single-threaded implementation is not very useful. MapReduce makes it very easy to scale data processing over multiple computing nodes.
b) The three stages are: map stage, shuffle stage, and reduce stage.  In the map stage the large amount of data is read in line by line by the mapper function and is made into several smaller data sets.  In the shuffle stage worker nodes redistribute data bases on output keys made in the map stage.  In the reduce stage, worker nodes now process the each group per key in parallel
