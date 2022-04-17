class Solution
{
public:
	long long waysToBuyPensPencils(int total, int cost1, int cost2)
	{
		long long res = 0;
		for (int cost = 0; cost <= total; cost += cost1)
			res += (total - cost) / cost2 + 1;
		return res;
	}
};