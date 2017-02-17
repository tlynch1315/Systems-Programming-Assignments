#!/bin/sh

num=5
descending=0

usage(){
  echo "Usage: rank.sh [-n N -D]
            -n N    Returns N items (default is 5).
            -D      Rank in descending order."
      exit $1
}

while [ $# -gt 0 ]; do
  case $1 in
    -n) num=$2 shift;;
    -D) descending=1;;
    *)  usage 0;;
  esac
  shift
done

if [ $descending -eq 1 ]; then    # sort in descending
  sort -nr | head -n "$num"
else
  sort -n | head -n "$num"
fi
