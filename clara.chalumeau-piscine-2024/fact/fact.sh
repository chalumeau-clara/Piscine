#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
else
    num=$1
    fact=1
    while [ $num -gt 1 ]; do
        fact=$((fact * num))
        num=$((num - 1))
    done
    echo $fact
fi
