#!/bin/sh

cut -d ':' -f 3 /etc/passwd | sort -rhu
