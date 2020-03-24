#include<stdio.h>
int main()
{
    int * getRow(int rowIndex,int *returnSize);
}
int * getRow(int rowIndex,int *returnSize)
{
    int *result =(int *)malloc(sizeof(int)*(rowIndex+1));
    int i;
    long tmp=1;
    *returnSize=rowIndex+1;
     result[0]=1;
     result[rowIndex]=1;
    
    if(rowIndex<2)
        return result;
    
    for(i=1;i<=rowIndex/2;i++)
    {
        tmp = tmp * (rowIndex - i + 1) /  i ;
        result[i]=result[rowIndex-i]=tmp;
    }
    return result;
}