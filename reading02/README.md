Reading 02
==========

1) To run this script without permission to execute, you use sh exists.sh because this will use sh to read the file and then execute it using sh

2) To make this executable you have to use chmod.  You could use chmod a+rx exists.sh to make it executable by everyone.

3) ./exists.sh

4) #!/bin/sh is a symbolic link to a sh, so all of the commands in the script are executed as if run through sh, just like if it was #!/bin/bash all of the commands would be executed as if through bash

5) The script outputs a list of all of the first file in the directory followed by "exists!"

6) $1 is the first additional parameter the script was called with

7) it tests to see if the first parameter that the script was called with is a file that exists

8) this script takes the first parameter called with it and if the parameter is an existing file, it returns "$1 exists!" and it not it returns "$1 does not exist!" where $1 is the first parameter called with the script


