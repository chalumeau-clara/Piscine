#!/bin/sh 

sort ~/.bash_history | cut -d ' ' -f1 | uniq -c | tr -s " " | cut -c 2- | sort -nr | head -n 10
