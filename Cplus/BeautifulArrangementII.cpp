#include <cmath>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> constructArray(int n, int k)
	{
		vector<int> res(n);
		int i = 2, j = n, index = 0;
		res[0] = 1;
		while (--k > 0)
		{
			if (abs(res[index] - i) >= abs(res[index] - j))
				res[++index] = i++;
			else
				res[++index] = j--;
		}
		if (index < n - 1)
		{
			int symbol = 1;
			if (res[index] - j == 1)
				symbol = -1;
			while (index < n - 1)
			{
				res[index + 1] = res[index] + symbol;
				++index;
			}
		}
		return res;
	}
};
