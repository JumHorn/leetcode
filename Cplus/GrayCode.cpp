#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> grayCode(int n)
	{
		if (n == 0)
			return {0};
		if (n == 1)
			return {0, 1};
		if (n == 2)
			return {0, 1, 3, 2};
		vector<int> res, seen(pow(2, n));
		res.push_back(0);
		seen[0] = 1;
		recursive(res, seen, 0, n);
		return res;
	}

	void recursive(vector<int>& res, vector<int>& seen, int n, int len)
	{
		for (int i = 0; i < len; i++)
		{
			int tmp = bitReverse(n, i);
			if (seen[tmp] == 0)
			{
				seen[tmp] = 1;
				res.push_back(tmp);
				recursive(res, seen, tmp, len);
				break;
			}
		}
	}

	int bitReverse(int num, int bit)
	{
		return ((~num) & (1u << bit)) | (num & (~(1u << bit)));
	}
};
