#include <vector>
using namespace std;

class Solution
{
public:
	int numOfSubarrays(vector<int> &arr)
	{
		int odd = arr[0] % 2, even = 1 - odd, res = odd;
		for (int i = 1; i < (int)arr.size(); ++i)
		{
			if (arr[i] % 2 == 0)
				++even;
			else
			{
				int next_odd = even + 1;
				even = odd;
				odd = next_odd;
			}
			res = (res + odd) % MOD;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};