#!/bin/sh


LOWER_SOURCE="abcdefghijklmnopqrstuvwxyz"
UPPER_SOURCE="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
if [[ $1 == "-h" ]]; then
  echo "Usage: caesar.sh [rotation] 
This program will read from stdin and rotate (shift right) the text by the specified rotation.  If none is specified, then the default value is
13."
exit 0;
fi

if [ -z $1 ]; then
  tr a-zA-Z n-za-mN-ZA-M    # default 13 rotation
else
  NUM=$(($1 % 26 + 1))      # in order to handle numbers over 26
  NUM_LOW=$((NUM-1))       
  LOWER_FIRST=$(echo "$LOWER_SOURCE" | cut -c $NUM)
  LOWER_SECOND=$(echo "$LOWER_SOURCE" | cut -c $NUM_LOW)
  UPPER_FIRST=$(echo "$UPPER_SOURCE" | cut -c $NUM)
  UPPER_SECOND=$(echo "$UPPER_SOURCE" | cut -c $NUM_LOW)

  tr [a-zA-Z] [$LOWER_FIRST-za-$LOWER_SECOND$UPPER_FIRST-ZA-$UPPER_SECOND]
fi

  
