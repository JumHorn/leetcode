#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> numsSameConsecDiff(int n, int k)
	{
		if (n < 2)
			return {};
		vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9}, next_v;
		for (int i = 1; i < n; ++i)
		{
			next_v.clear();
			for (auto n : v)
			{
				int val = n % 10;
				if (val + k <= 9)
					next_v.push_back(n * 10 + val + k);
				if (val - k >= 0 && k > 0)
					next_v.push_back(n * 10 + val - k);
			}
			v.swap(next_v);
		}
		return v;
	}
};