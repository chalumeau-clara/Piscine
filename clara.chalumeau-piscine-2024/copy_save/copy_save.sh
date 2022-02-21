#!/bin/sh

if [ $# -ne 1 ]; then
    echo "Usage: copy_save.sh file.csv"
    exit 1
fi

if [ ! -e $1 ]; then
    exit 1
fi

while IFS="," read fil; do
    FILENAME=$(basename -a ${fil})
        for i in $FILENAME; do
            if [ ! -r $i ]; then
                echo "$i: no such file"
                exit 1
            fi
        done
done < $1

mkdir "save"

while IFS="," read fil; do
    FILENAME=$(basename -a ${fil})
        for i in $FILENAME; do
            cp "$1" "save/$i"
        done
done < $1
