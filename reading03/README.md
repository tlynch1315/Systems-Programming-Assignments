Reading 03
==========

1) echo "All your base are belong to us" | tr '[:lower:]' '[:upper:]'

  tr translates the first character class into the second, which is lower to upper in this case

2) echo "monkeys love bananas" | sed -e "s/monkeys/gorillas/g"

  sed is a find and replace command

3) echo "    monkeys love bananas" | sed -e "s/^[[:space:]]*//"

*The sed in this case replaces all leading space with nothing because it does not use the global find and replace so it finds the first instance of the space character class and replaces that group with nothing

4) cat /etc/passwd | grep ^root | cut -d ":" -f 7 

  ^root makes it so that root has to be the first word in the line and then the cut uses : as a delimeter and displays the seventh subject field

5) cat /etc/passwd | sed -e 's#/bin/bash#/usr/bin/python#g; s#/bin/csh#/usr/bin/python#g; s#/bin/tcsh#/usr/bin/python#g' | grep python 

OR
  cat /etc/passwd | sed -e 's#/bin\(/bash\|/csh\|/tcsh\)#/usr/bin/python#g' | grep python

  the first command uses three separate find and replaces with # as a delimeter, while the second command does it all in one find and replace using back slashes and or

6) cat /etc/passwd | grep -E '4[0-9]*7'

*the grep searches for a string that starts with 4, has numbers following it and then 7 following those numbers

7) comm -12  <(sort file1.txt) <(sort  file2.txt)

  you need to sort the files because comm compares sorted files and the -12 shows the common lines

8) diff -u file1.txt file2.txt
  
  diff shows the different lines in the two files and -u displays the lines of each file and indicators next to each line to say whether it is unique to file one or two 

 
