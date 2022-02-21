#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

valid=0

if [ -s $1 ]; then
    valid=$((valid + 1))
fi

if [ $valid -eq 0 ]; then
    exit 1
fi

while IFS= read -r line; do
    if [ ${#line} -ge 80 ]; then
        printf "%s\n" "$line"
    fi
done < $1

exit 0
