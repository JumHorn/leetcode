#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> finalPrices(vector<int> &prices)
	{
		int N = prices.size();
		stack<int> s;
		for (int i = 0; i < N; ++i)
		{
			while (!s.empty() && prices[s.top()] >= prices[i])
			{
				prices[s.top()] -= prices[i];
				s.pop();
			}
			s.push(i);
		}
		return prices;
	}
};