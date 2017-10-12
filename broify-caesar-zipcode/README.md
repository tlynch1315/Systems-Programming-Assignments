Homework 03
===========
caesar.sh
    Takes text input and applies a caesar cypher to the text

broify.sh
    Takes a file as input and removes lines based on a delimiter

zipcode.sh
    returns zipcodes of a specified location using http://www.zipcodestogo.com/

ACTIVITY ONE
==============
1) I tested if the first parameter was "-h" and if it was it displayed a usage message and exited.  If it was not "-h" then I tested to see if a first parameter existed and if it did not then it just did a normal 13 rotation.  if there was a first parameter it took that number in and performed a modulo expression on it to determine how many characters to cut

2) the source sets were just the alphabet in upper and lower case

3) the target sets were set letters for the default, but for the non-default rotation I used cut -c with the source and a variable I called NUM to determine where to cut the source.  I used a modulo to get an integer less than or equal to 26 so that it could handle shifts of over 26

4) I used the sets to encrypt by using tr with [a-zA-Z] as the source set and the sets I made with the variables as the target set so that tr would shift the correct amount of characters

ACTIVITY TWO
==============
1) I parsed the command line arguments by using variables for the parameters and tested to see if any of the first few parameters was equal to one of the flags

2) I removed comments by using "s|$DELIM.*$||; 

*3) I removed empty lines by using "s|\s*$||; /^$/d"

*4) The command line arguments affected my script because it made me use if statements to test for flags and create variables for the delimiter

ACTIVITY THREE
================
1) I parsed the command line arguments by using variables for the parameters and then used a case for the flags

2) I extracted the zip codes using curl with the link and the state variable piped to two or more greps that specified the city if applicable and grepped a 5 digit number.

3) I filtered by state and city by using grep and using the varables state and city as filters.

4) I handled the text and csv formal by testing the format variable and if it was text, then I did not do anything out of the ordinary, but if the format variable was csv then I made new line characters periods by using tr "\n""."

 
