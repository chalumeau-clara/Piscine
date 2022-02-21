#!/bin/sh

if [ $# -ne 2 ]; then
    exit 1
fi

sed -n $2p $1 | sed 's/[^;]*;\([^;]*\)*;\([^;]*\).*/\1 is \2/'
