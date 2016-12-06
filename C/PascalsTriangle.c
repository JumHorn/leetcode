#include<stdio.h>
#include<malloc.h>
int main()
{
    int ** generate(int numRows,int ** columnSizes);
    int b[2];  //这里只是直接传递二级指针，所以要在函数内分配空间
    int **a;
    int i;
    generate(2,a);
    for(i=0;i<2;i++)
    {
        printf("%d\n",*a[i]);
    }
}

int ** generate(int numRows,int ** columnSizes)
{
    int **result,i,j;
    result=(int **)malloc(sizeof(int *)*numRows);
    columnSizes=(int **)malloc(sizeof(int *)*numRows);
    for(i=1;i<=numRows;i++)
    {
        columnSizes[i-1]=(int *)malloc(sizeof(int));
        *columnSizes[i-1]=i;
        result[i-1]=(int*)malloc(sizeof(int)*i);
        result[i-1][0]=1;
        result[i-1][i-1]=1;
    }
    if(i<3)
        return result;
    for(i=3;i<=numRows;i++)
    {
        for(j=1;j<i-1;j++)
        {
            result[i-1][j]=result[i-2][j]+result[i-2][j-1];
        }
    }
    return result;
}