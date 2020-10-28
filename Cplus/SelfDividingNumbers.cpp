#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> selfDividingNumbers(int left, int right)
	{
		vector<int> res;
		for (int i = left; i <= right; ++i)
		{
			if (selfDividing(i))
				res.push_back(i);
		}
		return res;
	}

	bool selfDividing(int n)
	{
		int num = n;
		while (num != 0)
		{
			int d = num % 10;
			if (d == 0 || n % d != 0)
				return false;
			num /= 10;
		}
		return true;
	}
};