#!/bin/sh

if [ $1 -lt 0 ]; then
    exit 1
fi

echo " _________________"
for i in $(seq 1 $1);
do
    if [ $2 = "square" ]; then
        echo "|  ___       ___  |
| |_|_|     |_|_| |
| |_|_|     |_|_| |
|                 |"
    else
        echo "|                 |
|   /\       /\   |
|  /__\     /__\  |
|                 |"
    fi
done

echo  "|        _        |
|       | |       |
|       | |       |
|_______| |_______|"

