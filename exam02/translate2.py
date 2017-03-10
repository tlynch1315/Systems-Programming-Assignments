#!/usr/bin/env python2.7

import requests
import re

URL = 'http://yld.me/aJt?raw=1'
r = requests.get(URL)
text = str(r.text.rstrip())
text = text.split('\n')


# grep -Eo '^[^aeoiu]*@.*'

wanted = set([line for line in text if re.search('[0-9]{3}-[0-9]{3}[13579]', line)])

for line in sorted(wanted):
  print line.split(',')[3]
