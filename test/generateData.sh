#!/bin/bash
int=1
a=$1
b=$1
val=`expr $a + $b`
echo $val > input.txt
while(($int<=${1}))
do
	echo "L ${int} 0 ${int} 1">>input.txt
	echo "L 0 ${int} 1 ${int}">>input.txt
	let "int++"
done

