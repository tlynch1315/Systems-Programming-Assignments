#!/usr/bin/env python2.7

import sys

counts = {}
for line in sys.stdin:
  k, v  = line.split('\t', 1)
  if counts.has_key(k) == False:
    counts[k] = set()
  counts[k].add(str(v).rstrip())

for k, v in sorted(counts.items()):
  print '{}\t{}'.format(k, ' '.join([i for i in sorted(v, key=float) if i != '']))
