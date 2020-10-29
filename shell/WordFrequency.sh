#!bin/bash

declare -A map=()
while read line
do
for n in $line
do
map["$n"]=`expr map["$n"] + 1`
done
done < words.txt
for n in ${!map[@]}
do
echo "$n ${map[$n]}"
done