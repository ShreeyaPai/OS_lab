#!/bin/bash

declare -A X
declare -A Y
declare -A Z

echo "Enter matrix 1"
for ((i=0;i<3;i++))
do
	for ((j=0;j<3;j++))
	do
		read X[$i,$j]
	done
done

echo "Enter matrix 2"
for ((i=0;i<3;i++))
do
	for ((j=0;j<3;j++))
	do
		read Y[$i,$j]
	done
done

echo "Matrix 1"
for ((i=0;i<3;i++))
do
	for ((j=0;j<3;j++))
	do
		echo -ne "${X[$i,$j]} "
	done
	echo
done

echo "Matrix 2"
for ((i=0;i<3;i++))
do
	for ((j=0;j<3;j++))
	do
		echo -ne "${Y[$i,$j]} "
	done
	echo
done

for ((i=0;i<3;i++))
do
	for ((j=0;j<3;j++))
	do
		Z[$i,$j]=$((X[$i,$j]+Y[$i,$j]))
	done
done

echo "Matrix 3"
for ((i=0;i<3;i++))
do
	for ((j=0;j<3;j++))
	do
		echo -ne "${Z[$i,$j]} "
	done
	echo
done
