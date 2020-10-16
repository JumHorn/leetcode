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
		unordered_set<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9}, next_s;
		for (int i = 1; i < n; ++i)
		{
			next_s.clear();
			for (auto n : s)
			{
				int val = n % 10;
				if (val + k <= 9)
					next_s.insert(n * 10 + val + k);
				if (val - k >= 0)
					next_s.insert(n * 10 + val - k);
			}
			s.swap(next_s);
		}
		return vector<int>(s.begin(), s.end());
	}
};