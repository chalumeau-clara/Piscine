#!/bin/sh
if [ $# -ne 3 ]; then
    1>&2 echo Usage: ./seq.sh FIRST INCREMENT LAST
    exit 1
fi

if [ $1 -eq $3 ]; then
    echo $1
    exit 0
elif [ $3 -gt $1 ]; then
    if [ $2 -le 0 ]; then
        exit 1
    fi
    n=$1
    two=$2
    while [ $3 -ge $n ] && [ $1 -le $n ]; do
        echo $n
        n=$((n + two))
    done
else
    if [ $2 -ge 0 ]; then
        exit 1
    fi
    n=$1
    two=$2
    while [ $3 -le $n ] && [ $1 -ge $n ];do
        echo $n
        n=$((n + two))
    done
fi
