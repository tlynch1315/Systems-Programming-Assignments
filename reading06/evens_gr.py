#!/usr/bin/env python2.7

import sys

def evens(stream):
  for x in stream:
    x = x.rstrip()
    if int(x) % 2 == 0:
      yield x


print ' '.join(evens(sys.stdin))
