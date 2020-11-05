#define min(a, b) (((a) < (b)) ? (a) : (b))

int minOperationsMaxProfit(int *customers, int customersSize, int boardingCost, int runningCost)
{
	int run = 0, maxRun = 1, profit = 0, maxprofit = profit, sum = 0;
	for (int i = 0; sum > 0 || i < customersSize; ++i)
	{
		if (i < customersSize)
			sum += customers[i];
		int bd = min(4, sum); // boarding people by greedy.
		sum -= bd;
		profit = profit + bd * boardingCost - runningCost;
		++run;
		if (profit > maxprofit)
		{
			maxprofit = profit;
			maxRun = run;
		}
	}
	return maxprofit > 0 ? maxRun : -1;
}