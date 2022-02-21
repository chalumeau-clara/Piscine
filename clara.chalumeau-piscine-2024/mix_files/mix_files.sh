#!/bin/bash

if [ $# -ne 2 ]; then
    1>&2 echo Usage: mix_files file1 file2
    exit 1
fi

#f1=($(< $1))
#f2=($(< $2))

i=0
while IFS='\n' read -r line1 && IFS='\n' read -r line2 <&3;
do
    echo "$line1"
    echo "$line2"
    i=$((i+1))
done < $1 3< $2

f5=$1
f6=$2
j=0
while IFS='\n' read -r line1;
do
    if [ $j -ge $i ]; then
        echo "$line1"
    fi
    j=$((j+1))
done < $2
j=0
while IFS='\n' read -r line1;
do
    if [ $j -ge $i ]; then
        echo "$line1"
    fi
    j=$((j+1))
done < $1
#cat out
#rm out
exit 0
