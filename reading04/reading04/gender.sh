#!/bin/sh

# gender.sh

URL=https://www3.nd.edu/~pbui/teaching/cse.20289.sp17/static/csv/demographics.csv

count_gender() {
    column=$(($1 % 2012 + ($1-2013)))
    gender=$2
    curl -L $URL 2> /dev/null | while read LINE; do
      cut -d ',' -f $column | grep "$gender"
    done | wc -w
}
for year in $(seq 2013 2019); do
    echo $year $(count_gender $year F) $(count_gender $year M)
done
