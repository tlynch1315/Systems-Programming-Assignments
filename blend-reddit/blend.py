#!/usr/bin/env python2.7

import atexit
import os
os.environ['PATH'] = '~ccl/software/external/imagemagick/bin:' + os.environ['PATH']
import re
import shutil
import sys
import tempfile

import requests

# Global variables

REVERSE     = False
DELAY       = 20
STEPSIZE    = 5

# Functions

def usage(status=0):
    print '''Usage: {} [ -r -d DELAY -s STEPSIZE ] netid1 netid2 target
    -r          Blend forward and backward
    -d DELAY    GIF delay between frames (default: {})
    -s STEPSIZE Blending percentage increment (default: {})'''.format(
        os.path.basename(sys.argv[0]), DELAY, STEPSIZE
    )
    sys.exit(status)

def remove_workspace():
  shutil.rmtree(directory)
  print 'Cleaning up workspace: ', directory, '\n'

def search_portrait(netid):
  r = requests.get('https://engineering.nd.edu/profiles/' + str(netid))
  if (r.text[0]):
    port = re.findall('<img src="(.*@@images.*?)"', r.text)
    print 'Searching portrait for ', netid, '...', port[0], '\n'
    return port[0]
  else:
    print 'Invalid netid'
    sys.exit(0)

def run(command):
  if(os.system(command) != 0):
    sys.exit(0)

def download_file(url, path):
  r = requests.get(url, stream = True)
  with open (path, 'wb') as output:
    output.write(r.content)
  return path

# Parse command line options

args = sys.argv[1:]

while len(args) and args[0].startswith('-') and len(args[0]) > 1:
    arg = args.pop(0)
    if arg == '-r':
      REVERSE = True
    elif arg == '-d':
      DELAY = int(args.pop(0))
    elif arg == '-s':
      STEPSIZE = int(args.pop(0))
      if STEPSIZE < 0 or STEPSIZE > 100:
        STEPSIZE = 5
        DELAY = 20
        usage(1)
    elif arg == '-h':
      usage(0)
    else:
      usage(1)

if len(args) != 3:
    usage(1)

netid1 = args[0]
netid2 = args[1]
target = args[2]

# Main execution

# TODO: Create workspace
  
directory = tempfile.mkdtemp()
print 'Using workspace: ', directory, '\n'


# TODO: Register cleanup

atexit.register(remove_workspace)


# TODO: Extract portrait URLs

url1 = search_portrait(netid1)
url2 = search_portrait(netid2)


# TODO: Download portraits
pic1 = os.path.join(directory, netid1 + '.jpeg')
pic2 = os.path.join(directory, netid2 + '.jpeg')

tempfile.pic1 = download_file(url1, pic1)
tempfile.pic2 = download_file(url2, pic2)


# TODO: Generate blended composite images
#print 'GENERATING'
files = []
num = 000
while num < 101:
  output = os.path.join(directory, '{:03d}-{}_{}.jpeg'.format(num,netid1,netid2))
  run('composite -blend {:03d} {} {} {}'.format(num, pic1, pic2, output))
  files.append(output)
  num = num + STEPSIZE


# TODO: Generate final animation
#print 'FINAL STEP'
joint = " ".join(files)
jointreverse = joint + " ".join(reversed(files))
if (REVERSE == True):
  run('convert -loop 0 -delay {} {} {}'.format(DELAY, jointreverse, target))
else:
  run('convert -loop 0 -delay {} {} {}'.format(DELAY, joint, target))    


