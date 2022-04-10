#include <vector>
using namespace std;

class Solution
{
public:
	int largestInteger(int num)
	{
		vector<int> count(10);
		for (int i = num; i > 0; i /= 10)
			++count[i % 10];
		int odd = 1, even = 0; //index
		long long res = 0, base = 1;
		for (int i = num; i > 0; i /= 10)
		{
			if (i % 10 % 2 == 0)
			{
				while (even < 10 && count[even] == 0)
					even += 2;
				--count[even];
				res = even * base + res;
			}
			else
			{
				while (odd < 10 && count[odd] == 0)
					odd += 2;
				--count[odd];
				res = odd * base + res;
			}
			base *= 10;
		}
		return res;
	}
};