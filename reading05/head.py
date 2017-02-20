#!/usr/bin/env python2.7

import os
import sys

# Global Variables
num=10
count=0
# Usage function

def usage(status=0):
    print '''Usage: {} files...

        -n NUM  print the first NUM lines instead of 10'''
    sys.exit(status)

# Parse command line options

args = sys.argv[1:]
while len(args) and args[0].startswith('-') and len(args[0]) > 1:
  arg = args.pop(0)
  if arg == '-n':
    num = int(args.pop(0))
  elif arg == '-h':
    usage(0)
  else:
    usage(1)
if len(args) == 0:
  args.append('-')

# Main execution

for path in args:
  if path == '-':
    stream = sys.stdin
  else:
    stream = open(path)
  #count = 0
  for line in stream:
    count = count + 1
    line = line.rstrip()
    if count > num:
      break
    print line

stream.close()
