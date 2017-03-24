Homework 06
===========

ACTIVITY ONE
==============
1) String_reverse_words works by reversing the entire string using string_reverse, then it uses two pointers and iterates the second while it is not equal to null and then while it is not a space, then sets begin = end, then moves the end pointer until it hits a null charachter or a space and then calls string_reverse_range(begin, end-1) to reverse that part of the string, which is just the current word, then it continues the iteration and goes to the next word until the end of the string.
    time-complexity: O(n) because it only iterates over the string once
    space-complexity: O(1) because it uses pointers and does not allocate any more memory

2) string_translate tests to see if the length of from is greater than to, and if it is it returns the input string.  if not, it enters a while loop that goes while *from is not null.*  in the while loop, there is a for loop that uses *c to iterate over the string and if *c == *from, then *c = *to, which maps the current from pointer to the current to pointer.*  after the for loop, the pointers are iterated and the for loop is entered again.
    time-complexity: O(n^2) because the for loop is in the while loop
    space-complexity: O(1) because no new variables are created

3) This function creates a char * pointing to the end of the string and tests if it is an alphabet letter and if is is, then it does the correct computation of multiplying the base by the value of end subtracted by either 'a' or 'A' + 10, which gives it the correct value for hexadecimal. if it is not an alphabet letter, it just subtracts '0' and does the correct calculaton to get the numerical value of the char, then it finally returns the result
    time-complexity: O(n) because it is just one while loop
    space-complexity: O(1) because you are only creating a set number of objects, it does not matter what the size of the input is

4) static libraries are linked to the file at compile time, while shared libraries are referenced by the program at run-time.
    the shared library is larger becuase it requires a copy of the library being used, which the static library does not need because it is linked at comilation

ACTIVITY TWO
==============
1) I parsed command line arguments just like we did in the other c programs we wrote such as grep.c and cat.c, only this time there were more options.
    All of the translations were implemented using functions from the stringutils library we made using a function with the stream, source, target, and mode as the inputs and if statements testing for each mode and chomping the input and translating it before the if statements.
    the post processing filters were used by using enum and the mode variables to test if mode and the variables in enum were true, then acting accordingly, either using the function or not.

2) the translate-static is much bigger, because it has all of the libraries statically linked at compilation. 
    translate-static and translate-dynamic do not work when run


