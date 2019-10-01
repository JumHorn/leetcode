#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * S, int* returnSize){
	int* res=(int*)malloc(sizeof(int)*2);
	*returnSize=2;
	int line=1,last=0;
	while(*S)
	{
		last+=widths[*S-'a'];
		if(last==100)
		{
			last=0;
			line++;
		}
		else if(last>100)
		{
			last=widths[*S-'a'];
			line++;
		}
		S++;
	}
	res[0]=line;
	res[1]=last;
	return res;
}



