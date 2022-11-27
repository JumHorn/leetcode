#include <string>
using namespace std;

class Solution
{
public:
	int bestClosingTime(string customers)
	{
		int penalty = 0;
		for (auto c : customers)
		{
			if (c == 'Y')
				++penalty;
		}
		int res = 0, p = penalty, y = 0, N = customers.size(), nocome = N - penalty;
		for (int i = 1; i < N; ++i)
		{
			if (customers[i - 1] == 'Y')
				--p;
			else
				++y;
			if (p + y < penalty)
			{
				penalty = p + y;
				res = i;
			}
		}
		if (penalty > nocome)
			return N;
		return res;
	}
};