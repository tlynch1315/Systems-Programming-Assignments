Reading 01
==========

1
===
a) the "|" is a pipeline that allows the stdout from the du -h /etc/ to be used as the stdin of sort
b) the 2> dev/null redirects the stderror to a null file so they are not included in the stdout when you hit enter
c) > output.txt redirects the output of sort to a text file called output.txt
d) -h puts SI Prefix on the output from du, such as MB or GB
e) The only difference is what error messages are suppressed.  Suppressing the error will make it so the error is redirected to dev/null instead of being displayed on the screen. The first command suppresses the error from du -h /etc/ and displays the error from sort while the second command suppresses the error from sort and will display the error from du -h /etc/
2
=====
a) cat 2002* > filename
b) cat *12 > filename
c) cat *{01..06} 
d) cat 200{2,4,6}-{01,03,05,07,09,11}
e) cat 200{2..4}-{09..12}

*3
=====
a) Huxley and Tux are executable by the owner since they have an x in the fourth file attribute
b) Huxley and Tux are executable by the users group since they have an r in the fifth file attribute
c) None of the files are writable by the world since the ninth file attribute of all of the files is -
d) chmod o+rx Tux or you could use chmod 755 Tux
e) chmod g-rx Tux or you could use chmod 600 Tux

4
=====
a) use Ctrl-Z to suspend it 
b) use fg to return the program to the foreground
c) use Ctrl-d
d) use Ctrl-c to terminate the process since it is in the foreground
e) use kill PID
PID is the process ID

