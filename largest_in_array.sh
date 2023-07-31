#!/bin/bash

read n
declare -A X
for ((i=0;i<n;i++))
do
	read X[$i]
done

max=${X[0]}

for ((i=1;i<n;i++))
do
	if [ ${X[$i]} -gt $max ]
	then max=${X[$i]}
	fi
done

echo $max
