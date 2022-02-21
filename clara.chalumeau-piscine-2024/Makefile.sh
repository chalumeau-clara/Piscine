#!/bin/sh

#for i in $(ls)
#do
#	[ -d $i ] && gcc -Wall -Wextra -Werror -pedantic -I./include -std=c99 "$i"/*.c && echo $i
#done


echo "looking for if( :"
for i in $(ls)
do
    [ -d "$i" ] && cat "$i"/*.c | grep "if(" && echo "in $i"
done
echo "looking for while( :"
for i in $(ls)
do
    [ -d "$i" ] && cat "$i"/*.c | grep "while(" && echo "in $i"
done

echo "looking for for( :"
for i in $(ls)
do
    [ -d "$i" ] && cat "$i"/*.c | grep "for(" && echo "in $i"
done

echo "looking for a+b instead of a + b :"
for i in $(ls)
do
    [ -d "$i" ] && cat "$i"/*.c | grep -e "?" && echo "in $i"
    [ -d "$i" ] && cat "$i"/*.c | grep -e "-?" && echo "in $i"
done

echo "looking for ' ;' :"
for i in $(ls)
do
    [ -d "$i" ] && cat "$i"/*.c | grep -e " ;" && echo "in $i"
done
