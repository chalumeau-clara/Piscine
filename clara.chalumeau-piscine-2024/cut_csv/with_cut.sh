#!/bin/sh
if [ $# -ne 2 ]; then
    exit 1
fi

cut -d ';' -f 2,3 $1 --output-delimiter=" is " | head -$2 | tail -1
