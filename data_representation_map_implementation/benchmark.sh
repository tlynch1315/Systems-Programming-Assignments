#!/bin/sh
# benchmark for merge and quicksort
MERGETIME=0
MERGESPACE=0
SPACES="         "
NUMSPACE=$((9-0))


echo '| NITEM     | ALPHA     | TIME     | SPACE     |
| --------- | --------  | -------- | --------- |'

for x in 1 10 100 1000 10000 100000 1000000 10000000
do
    for alpha in 0.5 0.75 0.9 1.0 2.0 4.0 8.0 16.0
    do
        MERGETIME=$(shuf -i1-100000000 -n $x | ./measure ./freq -l '$alpha' | tail -n 1 | cut -d 's' -f 1 | cut -c -8)
        MERGESPACE=$(shuf -i1-100000000 -n $x | ./measure ./freq -l '$alpha'| tail -n 1 | cut -d 's' -f 3 | cut -c 2-9)
        echo '| '$x"${SPACES::$NUMSPACE}"'| '$alpha'    | '$MERGETIME' | '$MERGESPACE'  |'
    done
    NUMSPACE=$((NUMSPACE-1))
done


