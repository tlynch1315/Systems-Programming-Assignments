#!/usr/bin/env python2.7

# cat /etc/passwd | cut -d : -f 5 | grep '[uU]ser' | tr 'A-Z' 'a-z' | sort

import re

with open('/etc/passwd', 'r') as f:
  lines = f.readlines()


fields = [line.split(':')[4] for line in lines]


grepped = set([line for line in fields if re.search('[uU]ser', line)])

result = [line.lower() for line in grepped]



for line in sorted(result):
  print ''.join(line)
