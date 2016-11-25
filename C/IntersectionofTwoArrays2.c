#include<stdio.h>
#include<malloc.h>
int main()
{
	int * intersection(int * nums1,int nums1Size,int * nums2,int nums2Size,int * returnSize);
	int a[]={1,2,2,1},b[]={1,2};
	int *p,i,size=2;
	p=intersection(a,4,b,2,&size);
	for(i=0;i<2;i++)
	{
		printf("%d\n",*p);
		p++;
	}
}

int * intersection(int * nums1,int nums1Size,int * nums2,int nums2Size,int * returnSize)
{
	int a[1000]={0};
	int i,j,k=0;
	int *p1,*p2;
	*returnSize=0;
	p1=nums1;
	p2=nums2;
	for(i=0;i<nums1Size;i++,p1++)
	{
		for(j=0,p2=nums2;j<nums2Size;j++,p2++)
		{
			if(*p1==*p2)
			{
				a[k++]=*p1;
                                *p2=-200;
				break;
			}
		}
	}
	*returnSize=k;
	int * p = (int*)malloc(sizeof(int)*(*returnSize));
	p1=p;
	for(i=0;i<k;i++)
	{
		*p1++=a[i];
	}
	return p;
}
