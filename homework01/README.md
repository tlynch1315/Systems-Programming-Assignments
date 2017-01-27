Homework 01
===========
ACTIVITY ONE
==============

1
====
a) The following users, followed by their specific rights,  have normal rights to all of the three directories: tlynch2 rlidwka and system:administrators rlidwka. In my home directory, nd_campus l and system:authuser l have normal rights, but do not have normal rights in my Public or Private directories.  In my Public directory nd_campus rlk and system:authuser rlk have normal rights but do not have normal rights in my Home or Private directories.
b) the ACL that makes Private private is tlynch2 since I am the only one other than the administrators that can do anything to this directory. the ACLs that makes my Public directory public are nd_campus and system:authuser because this means that anyone on campus can see my directory and any authorized user can see it.

2
====
a) I was not able to create the file, I recieved a message telling me that permission was denied.
b) based on this result, the ACLs take precedence over Unix permissions because I was denied permission to this directory.

ACTIVITY TWO
==============

| command               | elapsed time |
|--------------------------------------|
|cp ...                 | 1.676s       |
|mv ...                 | 0.003s       |
|mv ...                 | 1.496s       |
|rm ...                 | 0.009s       |

1
====
renaming is faster because it kept all of the files in the same directory, while when it was moved the files had to be put into memory and then put into a separate directory and then deleted from the original directory, which takes longer than just keeping the files in the same directory.

2
====
the remove operation does not have to put the contents of what its deleting into memory, so it is much faster than moving, which requires memory usage

ACTIVITY THREE
================

1) bc < math.txt
2) bc < math.txt > results.txt
3) bc < math.txt > results.txt 2> /dev/null
4) cat math.txt | bc    this is less efficient because it is running two separate commands instead of one and just redirecting the outputs

ACTIVITY FOUR
===============

1) grep /sbin/nologin /etc/passwd | wc -l
2) who -u | cut -d ' ' -f 1 | sort | uniq | wc -l
3) du -a /etc 2> /dev/null | grep etc/ | sort -nr | head -n 5
4) ps -e | grep bash | wc -l

ACTIVITY FIVE
===============

1
====
a) I tried to use Ctrl-C first, and when that did not work I used Ctrl-Z to suspend the process.  Once the process was suspended, I tried to use the kill command without any flags, but that did not work.
b) Once I looked back at the textbook I saw the -KILL flag for the kill command and used that and it ended the process.

2
====
a) pgrep -u tlynch2 TROLL | xargs kill -KILL
b) killall -KILL TROLL 2> /dev/null

3
====
kill -HUP $(pgrep -u tlynch2 TROLL)
  "You used to call me on my cell phone"

kill -7 $(pgrep -u tlynch2 TROLL)
  "The Vengabus is coming / And everybody's jumping"

kill -10 $(pgrep -u tlynch2 TROLL)
  starts cmatrix

