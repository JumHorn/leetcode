#include<stdlib.h>

typedef struct _Weight
{
	int weight;
	int index;
}Weight;

int comp(const void *lhs,const void *rhs)
{
	Weight* l=(Weight*)lhs;
	Weight* r=(Weight*)rhs;
	return l->weight-r->weight;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
	Weight *w=(Weight*)malloc(costsSize*sizeof(Weight));
	for(int i=0;i<costsSize;i++)
	{
		w[i].index=i;
		w[i].weight=costs[i][1]-costs[i][0];
	}
	qsort(w,costsSize,sizeof(Weight),comp);
	int res=0;
	for(int i=0;i<costsSize/2;i++)
		res+=costs[w[i].index][1];
	for(int i=costsSize/2;i<costsSize;i++)
		res+=costs[w[i].index][0];
	return res;
}
