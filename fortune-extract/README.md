Homework 02
===========

ACTIVITY ONE
==============
1) In extract.sh, I tested to see if there was a parameter after the command using [ -z "$1" ] and if this is true then a usage message is displayed and the script exits

2) I determined which command to use by reading the book and looking up how to extract files given a certain type of compressed file

3) The most difficult part of writing this script was figuring out what flags to use with tar and I overcame it by reading tar man and using the internet to find out which flags to use for which types of files

ACTIVITY TWO
==============
1) I created a function called get_message() that shuffled messages and piped the first saying into cowsay

2) I used a trap with the early_exit function to display a message

3) i used read -p with a variable to get the input from a user

4) figuring out how to get the "Question? " to appear if nothing was entered.  I had to put quotes around the variable "$INPUT_STRING"

ACTIVITY THREE
================
1) first step: locate oracle by scanning `xavier.h4x0r.space` for a HTTP port
    command
      nmap -PN -p9000-9999 xavier.h4x04.space
    output:

Starting Nmap 5.51 ( http://nmap.org ) at 2017-02-03 17:42 EST
Nmap scan report for xavier.h4x0r.space (129.74.160.130)
Host is up (0.00047s latency).
Not shown: 997 closed ports
PORT     STATE SERVICE
9097/tcp open  unknown
9111/tcp open  DragonIDSConsole
9876/tcp open  sd

Nmap done: 1 IP address (1 host up) scanned in 0.07 seconds

clearly there are 3 ports in the 9000 range

2) second step: try to access HTTP servers, I tried each port until finding something about lockboxes and this is what happened:
    command
      curl xavier.h4x0r.space:9876
    output


 ________________________________________ 
/ Halt! Who goes there?                  \
|                                        |
| If you seek the ORACLE, you must come  |
| back and _request_ the DOORMAN at      |
| /{NETID}/{PASSCODE}!                   |
|                                        |
| To retrieve your PASSCODE you must     |
| first _find_ your LOCKBOX which is     |
| located somewhere in                   |
| ~pbui/pub/oracle/lockboxes.            |
|                                        |
| Once the LOCKBOX has been located, you |
| must use your hacking skills to        |
| _bruteforce_ the LOCKBOX program until |
| it reveals the passcode!               |
|                                        |
\ Good luck!                             /
 ---------------------------------------- 
        \  ^___^
         \ (ooo)\_______
           (___)\       )\/\
                ||----w |
                ||     ||

3) to find my lockbox I changed to the lockboxes directory and used :

    find | grep | tlynch2 | grep lockbox

    output:
      
./af0abfc6/2b783d9a/3e1c87c6/68c16c6a/tlynch2.lockbox

4)
    to try to get the password, I created a script that runs the lockbox command with each readable word, found by the strings command

    script:
      #!/bin/sh
      
      for i in $(strings tlynch2.lockbox)
      do
        tlynch2.lockbox $i
      done

    output:
      
      65aeed1014414e523716e9a4c77ce7fe

so the output is the password

5) I now am going to try to request the oracle
    
    command:
        curl -vv xavier.h4x0r.space:9876/tlynch/{passcode}
    output:
        message telling me to slack and type in a message

6) once I typed the message on slack, I got a message to send to the oracle

    command
        nc xavier.h4x0r.space 9111
    output
        asked for my name and I said tlynch2 then put the password from slack and I accessed the oracle


    
