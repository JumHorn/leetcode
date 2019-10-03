#include<stdlib.h>


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes){
	int len=R*C;
	int** res=(int**)malloc(sizeof(int*)*len);
	for(int i=0;i<len;i++)
		res[i]=(int*)malloc(sizeof(int)*2);
	*returnSize=len;
	*returnColumnSizes=(int*)malloc(len*sizeof(int));
	for(int i=0;i<len;i++)
		(*returnColumnSizes)[i]=2;
	res[0][0]=r0;
	res[0][1]=c0;
	int **board=(int **)malloc(sizeof(int*)*R);
	for(int i=0;i<R;i++)
		board[i]=(int*)calloc(C,sizeof(int));
	board[r0][c0]=1;
	int top=0,push=1;
	while(top<len)
	{
		int x=res[top][0],y=res[top][1];
		if(x-1>=0&&board[x-1][y]==0)
		{
			board[x-1][y]=1;
			res[push][0]=x-1;
			res[push][1]=y;
			push++;
		}
		if(x+1<R&&board[x+1][y]==0)
		{
			board[x+1][y]=1;
			res[push][0]=x+1;
			res[push][1]=y;
			push++;
		}
		if(y-1>=0&&board[x][y-1]==0)
		{
			board[x][y-1]=1;
			res[push][0]=x;
			res[push][1]=y-1;
			push++;
		}
		if(y+1<C&&board[x][y+1]==0)
		{
			board[x][y+1]=1;
			res[push][0]=x;
			res[push][1]=y+1;
			push++;
		}
		top++;
	}
	return res;
}

