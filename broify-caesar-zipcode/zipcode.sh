#!/bin/sh

city=NA
format=text
state=Indiana

if [ "$1" == "-h" ]; then
  echo "Usage: zipcode.sh
        
          -c  CITY    Which city to search
          -f  FORMAT  Which format(text,csv)
          -s  STATE   Which state to search(INDIANA)
  
          If no state is specified, then all of the zip codes from the state are displayed"
  exit 0
fi

while [ $# -gt 0 ]
do
  case $1 in
    -c) 
      city="$2"
      shift
      ;;
    -f)
      if [ $2 != "text" ] && [ $2 != "csv" ]; then
        echo "invalid format"
        exit 1
      fi
      format="$2"
      shift
      ;;
    -s)
      state=$(echo "$2" | sed 's| |%20|' )
      shift
      ;;
  esac
  shift
done

if [ "$city" == NA ] && [ $format == text ]; then
  curl -s http://www.zipcodestogo.com/$state/ | grep -Eo '>[0-9]{5}<'| grep -Eo [0-9]{5}

elif [ "$city" != NA ] && [ $format == text ]; then
  curl -s http://www.zipcodestogo.com/$state/ | grep -E "/$city/" | grep -Eo '>[0-9]{5}<' | grep -Eo [0-9]{5}

elif [ "$city" == NA ] && [ $format == csv ]; then
  curl -s http://www.zipcodestogo.com/$state/ | grep -Eo '>[0-9]{5}<'| grep -Eo [0-9]{5} | tr "\n""."

elif [ "$city" != NA ] && [ $format == csv ]; then
  curl -s http://www.zipcodestogo.com/$state/ | grep -E "/$city/" | grep -Eo '>[0-9]{5}<'| grep -Eo [0-9]{5} | tr "\n""."

fi

exit 1


