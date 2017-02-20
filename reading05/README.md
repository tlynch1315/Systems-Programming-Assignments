Reading 05
==========
1
=====
1) the import sys allows you to use command line arguments in the script
2) this line iterates through the command line arguments starting with the first index, which is the argument after the script is called
3) the trailing ',' makes the output one line because it prevents a new line from being printed with the print function

2
=====
1) The len(args) will return false if args does not exist, and the args.startwith('-') tests if the argument starts with a '-', making sure it is a flag, and the last conditional len(args[0]) > 1 tests to see if the argument is not just a '-'
2) 
  a) These lines add a '-' to the command line arguments if there were no command line arguments other than flags, which were all popped in the while loop.  If there was another argument, the '-' would not be added becaus the while loop would exit since the argument did not start with a '-'
  b) these lines test decide what the stream is.  If the if statement from a added a '-' then the stream is the stdin, but if there was another argument that was not a flag, then the stream was that argument
3) it is necessary if you want the $ to be at the end of the characters, not at the end of the trailing whitespace because line.rstrip() strips the line of all trailing whitespace


