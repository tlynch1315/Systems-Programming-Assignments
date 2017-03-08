#!/usr/bin/env python2.7
#map.py

import sys
count = 1
alphabet = 'abcdefghijklmnopqrstuvwxyz-'
for line in sys.stdin:
  for word in line.strip().split():
    print '{}\t{}'.format(''.join([letter.lower() for letter in word if letter.lower() in alphabet]), count)
  count += 1
