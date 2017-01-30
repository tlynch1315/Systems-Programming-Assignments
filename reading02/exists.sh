#!/bin/sh

if [ -z "$1" ]; then
  echo "Error: no input"
else 
  for i in $@
  do
  if [ -e "$i" ]; then
    echo "$i exists!"
  else
    echo "$i does not exist!"
  fi
  done
fi

