Homework 05
===========
ACTIVITY ONE
==============
1)
a) I generated all the candidate password combinations by making a set called password using line.rstrip() for line in open(HASHES), which iterates over the HASHES file and creates a set that contains each line of the HASHES file, stripping the newline character from each line.
b) I filtered the candidates to only contain valid passwords by using list comprehension in the smash function.  It returns the prefix + the permutation if the md5sum of the prefix + permutation is in the hashes
c) I handled process on multiple cores by using an if statement that tests if the length > 1 and the cores > 1, and if they are, then then another if statement tests if the length > 4 and if it is the prefix length is set to 2 and if not it is set to 1.  then, a list of prefixes is made using the permutations function, and then another list of prefixes is made that just adds the PREFIX variable to each prefix in the list of prefixes.  Once this is done and the set of passwords is made, then a pool is created of the specified amount of cores, and then the program uses the itertools.chain.from_iterable(...) along with the pool.imap(...) function to create a list of confirmed passwords
d) I verified that my code runs properly by running the doctest and the test_hulk.py script


2)
CORES ||  TIME
------------------
1       152m42.192s
------------------
2       97m48.179s
------------------
4       71m44.142s
------------------
8       24m19.708s
------------------
16      20m1.889s
------------------
As the number of processes being utilized increases, the amount of time required decreases.  This is because the amount of permutations of length 6 is very large, so splitting it up among more processes helps, but if the length were shorter, say 3, increasing the amount of processes may not help as much


3) It really depends upon how much more complex the alphabet is.  If the alphabet is double the length, it would take much longer than increasing the password by a small amount, but if you increase them by the same amount, say 37 length alphabet and 7 length password, increasing the password length has more of an affect than increasing the alphabet length 

ACTIVITY TWO
==============
1) 
  a) iv_map.py keeps track of line numbers using a counter that is incremented in the outside for loop
  b) it checks if the letter.lower() in each word of each line is in a set of letters called alphabet, which is the set of all lower case letters and '-'

2)
  a) iv_reduce.py aggregates the results for each word by creating a set for each key in counts, then adds the stripped string of the line number to the key, and because its a set, it won't have any duplicates
  b) it outputs the results in the correct format by sorting the set that is the value for each key in the dictionary, and uses a list comprehension to output each value in the set as a float if the value is not ''



