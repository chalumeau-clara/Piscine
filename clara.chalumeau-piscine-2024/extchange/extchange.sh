#!/bin/sh

if [ $# -ne 2 ]; then
    echo Usage: extchange.sh "'ext1'" "'ext2'"
    exit 1
fi

match=0

for f in *.$1;
do
    if [ -f "$f" ]; then
        match=$((match+1))
    fi
done

if [ $match -eq 0 ]; then
    exit 2
fi

for f in *.$1;
do
    echo "mv $f ${f%$1}$2"
    mv -- "$f" "${f%.$1}.$2"
done

exit 0
