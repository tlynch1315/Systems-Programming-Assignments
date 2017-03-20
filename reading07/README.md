Reading 07
==========
ACTIVITY ONE
===============
1) This line tests to see if the index 'i' is less than the size entered, which in this case is 1<<10, or 1024, and if the input number is not EOF, or end of file.  The scanf assigns the input value to the numbers[i] and the & in front of the numbers[i] makes it so that the numbers array at the position i is globally set to the input value.

2) You cannot replace the size_t n with sizeof because the size_t is just an unsigned int that is assigned using the read_numbers function, which iterates over the array and increments the variable being returned by one each time there is a valid value in the array of numbers. This means that using the function and a size_t, you get the amount of elements in the array, but using sizeof, you get the size of the array in bytes, which will include all the memory that was allocated to the array, not just the amount of elements that have a valid value, so this will take into account all of the elements that have not been explicitly assigned a value and will mess up the calculation.


ACTIVITY TWO
==============
1) This program uses argc and argv to parse command line arguments, while the python script just used sys.argv to parse them.  This uses the argc to get the count of command line arguments while using the argv to iterate over the arguments.  The python script used pop to get the current argument, and it also shortened the list so you could test for the length of the list being > 0, but here it iterates over the arguments using ++ because pop is not available.

2) This code tests if the index for the arguments is less than the amount of arguments, and if it is then the char *path is set equal to the current index in the arguments then iterated using ++.* Then if the strcmp between path and "-" == 0 the program runs cat_stream(stdin).  this is run when the path is either empty or is "-".  If the program does not enter this if statement, then the else statement is run and cat_file(path) is called, which cats the file in the argument line

3) cat_stream creates an array of chars of BUFSIZ, which is just a specified size based on the compiler being used.  Then, while fgets has something to get from stream, which is stdin in this case, it stores one line at a time in the buffer array and then fputs outputs the buffer to stdout and the loop continues to the next line.

4) cat_file opens a pointer to a file that is just made readable using fopen, and if the pointer points to null, then the stderror is printed and the function exits. the stderror(errno) prints a string value for the error number. If the function does not go into the if statement, that means that the file exists, and then cat_stream(fs) is run, which cats the file and then fclose(fs) closes the file that was pointed to.


