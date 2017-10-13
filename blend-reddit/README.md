Homework 04
===========
blend.py
    python script that creates a gif blending two Notre Dame staff members together based on the input of the user

reddit.py
    python script that scrapes reddit rubreddits and returns articles based on a specifications given by the user


ACTIVITY ONE 
===============
1) I parsed command line arguments using .pop() along with conditional statements

2) I managed the temporary workspace by using mkdtemp() and os.path to edit the path to the temporary directory made using mkdtemp()

3) I extracted the portrait URL's using requests.get() with re.findall() using a regular expression to find the image on the page of the netid given and returning the first index of the list as the URL that is to be downloaded

4) I downloaded the files first by ammending the path that it is to be downloaded to using os.path.join, then used my download_file function with the URL and the path as the arguments and then used requests.get and opened the path argument and wrote the content of the requests.get to the path.

5)I generated the blended images using a while loop to iterate until a number exceeded 100.  the commands from ImageMagick were used with the run function, which determined if it was an os.system command and the list of files was appended to include the new file generated with the composite -blend command and the number was incremented by the stepsize

6) the final gif was created using the convert -loop command from ImageMagick.  the files were joined into one string using .join(files) and if the reverse was True, then the reversed files were added to the original joined files and used in the loop

7) I checked for failures by inputting different names and numbers

ACTIVITY TWO
==============
1) I parsed command line arguments using .pop() along with conditional statements

2) I fetched JSON data using a requests.get() along with .json() to get all of the json data from a certain subreddit 

3) I filtered each article based on FIELD and REGEX by first checking if the field was in the json data currently being assessed in the for loop and then after that checked if the regex was in the field of that data.

4) I did not shorten my URL because of the email that Pbui sent.
