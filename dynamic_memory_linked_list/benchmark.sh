#!/bin/sh
# benchmark for merge and quicksort
MERGETIME=0
MERGESPACE=0
QUICKTIME=0
QUICKSPACE=0
SPACES="         "
NUMSPACE=$((9-0))


echo '| NITEM     | SORT     | TIME     | SPACE     |
| --------- | -------- | -------- | --------- |'

for x in 1 10 100 1000 10000 100000 1000000 10000000
do
    MERGETIME=$(shuf -i1-100000000 -n $x | ./measure ./lsort -n | tail -n 1 | cut -d 's' -f 1 | cut -c -8)
    MERGESPACE=$(shuf -i1-100000000 -n $x | ./measure ./lsort -n | tail -n 1 | cut -d 's' -f 3 | cut -c 2-9)
    QUICKTIME=$(shuf -i1-100000000 -n $x | ./measure ./lsort -n -q | tail -n 1 | cut -d 's' -f 1 | cut -c -8)
    QUICKSPACE=$(shuf -i1-100000000 -n $x | ./measure ./lsort -n -q | tail -n 1 | cut -d 's' -f 3 | cut -c 2-9)
    echo '| '$x"${SPACES::$NUMSPACE}"'| Merge    | '$MERGETIME' | '$MERGESPACE'  |'
    echo '| '$x"${SPACES::$NUMSPACE}"'| Quick    | '$QUICKTIME' | '$QUICKSPACE'  |'
    NUMSPACE=$((NUMSPACE-1))
done


