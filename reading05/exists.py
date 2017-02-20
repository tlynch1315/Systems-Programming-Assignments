#!/usr/bin/env python2.7

import sys
import os.path
if len(sys.argv) < 2:
  print "Error: no input"
else: 
  for arg in sys.argv[1:]:
    if os.path.isfile(arg):
      print arg + " exists"
    else:
      print arg + " does not exist"
      sys.exit(1)
sys.exit(0)
