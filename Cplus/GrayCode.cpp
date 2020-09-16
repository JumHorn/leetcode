#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> grayCode(int n)
	{
		vector<int> res;
		int mask = 0;
		recursive(res, mask, n);
		return res;
	}

	void recursive(vector<int> &res, int &mask, int n)
	{
		if (n == 0)
		{
			res.push_back(mask);
			return;
		}
		recursive(res, mask, n - 1);
		mask = bitFlip(mask, n - 1);
		recursive(res, mask, n - 1);
	}

	int bitFlip(int num, int bit)
	{
		return num ^ (1 << bit);
	}
};