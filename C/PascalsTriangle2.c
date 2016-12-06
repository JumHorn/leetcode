#include<stdio.h>
int main()
{
    int * getRow(int rowIndex,int *returnSize);
    int combine(m,n);
}

int combine(m,n)
{
    if (n==0||n==m)
    {
        return 1;
    }
    else if (n==1)
    {
        return m;
    }
    else
    {
        return combine(m-1,n-1)+combine(m-1,n);
    }
}

int * getRow(int rowIndex,int *returnSize)
{
    int *result =(int *)malloc(sizeof(int)*(rowIndex+1));
    int i;
    *returnSize=rowIndex+1;
    if (rowIndex<2)
    {
        for(int i=0;i<=rowIndex;i++)
        {
            result[i]=1;
        }
        return result;
    }
    for(i=0;i<=rowIndex/2;i++)
    {
        result[i]=result[rowIndex-i]=combine(rowIndex,i);
    }
    return result;
}