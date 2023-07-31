#!/bin/bash
read n
len=${#n}
for (( i=$len-1;i>=0;i-- ))
	do
	rev=$rev${n:$i:1}
	done
echo $rev
if [ $n == $rev ]
then echo "Palindrome"
else
	echo "Not a palindrome"
fi
