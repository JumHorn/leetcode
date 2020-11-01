
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize)
{
	*returnSize = pricesSize;
	int stack[pricesSize], top = -1;
	for (int i = 0; i < pricesSize; ++i)
	{
		while (top != -1 && prices[stack[top]] >= prices[i])
			prices[stack[top--]] -= prices[i];
		stack[++top] = i;
	}
	return prices;
}
