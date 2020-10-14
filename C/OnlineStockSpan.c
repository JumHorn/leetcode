#include <limits.h>
#include <stdlib.h>

typedef struct
{
	int stack[10000][2];  //{index,value}
	int top;
	int index;  //current index
} StockSpanner;

StockSpanner* stockSpannerCreate()
{
	StockSpanner* stock = (StockSpanner*)malloc(sizeof(StockSpanner));
	stock->top = stock->index = 0;
	stock->stack[0][0] = -1;
	stock->stack[0][1] = INT_MAX;
	return stock;
}

int stockSpannerNext(StockSpanner* obj, int price)
{
	while (obj->stack[obj->top][1] <= price)
		--obj->top;
	int res = obj->index - obj->stack[obj->top][0];
	obj->stack[++obj->top][0] = obj->index++;
	obj->stack[obj->top][1] = price;
	return res;
}

void stockSpannerFree(StockSpanner* obj)
{
	if (obj)
		free(obj);
}

/**
 * Your StockSpanner struct will be instantiated and called as such:
 * StockSpanner* obj = stockSpannerCreate();
 * int param_1 = stockSpannerNext(obj, price);
 
 * stockSpannerFree(obj);
*/
