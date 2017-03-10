#!/usr/bin/env python2.7

import os

#get results of 'who' command
x = os.popen('ps aux', 'r')

#get list of lines from os.popen
#have to convert to string so the sort is a string sort not a numerical sort
lines = set([str(line.split()[0]) for line in x.read().rstrip().split('\n')])

count = 0
result = dict()
for x in lines:
  if x not in result.keys():
    result.update({x:1})
    count += 1
  else:
    result[x] = result[x] + 1
print count



