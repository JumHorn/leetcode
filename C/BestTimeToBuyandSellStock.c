#include<stdio.h>
int main()
{
	int maxProfit(int * prices,int pricesSize);
}

int maxProfit(int * prices,int pricesSize)
{
	int i,min=2147483647,max=0;
	for(i=0;i<pricesSize;i++)
	{
                min=prices[i]>min?min:prices[i];
		if(prices[i]-min>max)
		{
			max=prices[i]-min;
		}

	}
	return max;
}
