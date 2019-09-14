#include<stdlib.h>
#define swap(a,b) if((a)!=(b)) (a)^=(b)^=(a)^=(b)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numMovesStones(int a, int b, int c, int* returnSize){
	*returnSize=2;
	if(a>c)
		swap(a,c);
	if(a>b)
		swap(a,b);
	if(b>c)
		swap(b,c);
	int* res=(int*)malloc(2*sizeof(int));
	if(c-a==2)
		res[0]=0;
	else if(b-a==1||c-b==1||b-a==2||c-b==2)
		res[0]=1;
	else
		res[0]=2;
	res[1]=b-a-1+c-b-1;
	return res;
}
