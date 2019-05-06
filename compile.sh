#!/bin/bash

COMPILE=0
FILENAME="test.c"
RESULT="test"
COMMAPND=""

while getopts cf:n: OPT
do
    case $OPT in
        c)  COMPILE=1
            ;;
        f)  FILENAME=$OPTARG
            ;;
        n)  RESULT=$OPTARG
            ;;
        *)
	    exit 1
            ;;
    esac
done

echo $FILENAME
echo $RESULT

if [ $COMPILE = 1 ]; then
    echo "Start Compile $FILENAME"
    gcc $FILENAME -o $RESULT
else
    echo "Not Start Compile"
fi

