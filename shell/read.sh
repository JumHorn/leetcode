#!bin/bash

while read line;
do
echo $line;
for n in $line;
do
echo $n;
done
done < words.txt