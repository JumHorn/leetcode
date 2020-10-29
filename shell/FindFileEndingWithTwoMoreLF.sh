
function file_ends_with_newline()
{
	c=`tail -c2 $1 | wc -l`
	if [ $c -gt 1 ];then
    	echo $1
	fi
}

files=`ls *.c`
for file in ${files[@]};do
	file_ends_with_newline "$file"
done
