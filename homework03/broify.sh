#!/bin/sh
if [ "$1" == "-h" ]; then
  echo "Usage: broify.sh
          -d DELIM  Use this as the comment delimiter
          -W        don't strip any lines
"
  exit 1
fi

if [ "$1" == "-d" ] && [ "$3" != "-W" ]; then
  DELIM=$2
  # get rid of everything using delimiter
  sed "s|$DELIM.*$||; s|\s*$||; /^$/d"

elif [ $# -eq 0 ]; then
  DELIM="#"
  # Get rid of everything
  sed "s|$DELIM.*$||; s|\s*$||; /^$/d"

elif [ "$3" == "-W" ]; then
  DELIM=$2
  # dont strip empty lines
  sed "s|$DELIM.*$||; s|\s*$||"

elif [ "$1" == "-W" ]; then
  DELIM="#"
  # dont strip empty lines
  sed "s|$DELIM.*$||; s|\s*$||"

fi
