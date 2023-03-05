#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int findValidSplit(vector<int> &nums)
	{
		unordered_map<int, int> m1, m2; //{primer,count}
		int N = nums.size();
		for (auto n : nums)
		{
			for (int i = 2; i * i <= n; ++i)
			{
				for (; n % i == 0; n /= i)
					++m1[i];
			}
			if (n > 1)
				++m1[n];
		}
		for (int i = 0; i < N - 1; ++i)
		{
			int n = nums[i];
			for (int i = 2; i * i <= n; ++i)
			{
				int count = 0;
				for (; n % i == 0; n /= i)
				{
					if (--m1[i] == 0)
						m1.erase(i);
					++m2[i];
				}
			}
			if (n > 1)
			{
				if (--m1[n] == 0)
					m1.erase(n);
				++m2[n];
			}
			if (check(m1, m2))
				return i;
		}
		return -1;
	}

	bool check(unordered_map<int, int> &m1, unordered_map<int, int> &m2)
	{
		for (auto [p, c] : m2)
		{
			if (m1.find(p) != m1.end())
				return false;
		}
		return true;
	}
};