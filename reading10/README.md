Reading 10
==========

ACTIVITY ONE
==============
1)  I would use 
    execl("command");
    perror("");
    which would just print the error message because the string inside of the () is just a blank string so nothing would go before the error message.

2) i would use 
    int truncate( const char *path, off_t length)
    this would truncate a file given by the path variable to the length provided.

3) i would use
    fseek(fp, 10, SEEK_SET)
    fp is the file path, 10 means the 10th byte, and SEEK_SET is telling it to go from the beginning of the file

4) to check if a path is a directory, i would do:
    struct stat s;
    if(stat(path, &s) == 0){
        if(s.st_mode & S_ISDIR) return true;
    }
    return false;

    This tests to see if the path is a directory using stat() and the S_IFDIR macro.

5) to create a copy of a process:
    fork();

6) to replace the code in a current process:
    exec();

7) to terminate a process:
    kill -(SIGINT, SIGQUIT, or SIGKILL) -PID

8) To retrieve the exit status of a child process:
    WIFEXITED(status) or WEXITSTATUS(status)


