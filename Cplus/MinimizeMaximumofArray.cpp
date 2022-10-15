#include <vector>
using namespace std;

class Solution
{
public:
	int minimizeArrayValue(vector<int> &nums)
	{
		vector<pair<int, int>> s;  //{val,count} use as stack
		s.push_back({nums[0], 1}); //dummy
		for (int i = 1; i < nums.size(); ++i)
		{
			int n = nums[i];
			if (n > s.back().first)
			{
				long long val = s.back().first;
				long long count = s.back().second + 1;
				long long delta = n - val;
				s.pop_back();
				while (!s.empty() && (s.back().first - val) * count <= delta)
				{
					delta -= (s.back().first - val) * count;
					val = s.back().first;
					count += s.back().second;
					s.pop_back();
				}
				if (delta % count != 0)
					s.push_back({val + delta / count + 1, delta % count});
				s.push_back({val + delta / count, count - delta % count});
			}
			else if (n == s.back().first)
				++s.back().second;
			else
				s.push_back({n, 1});
		}

		return s[0].first;
	}
};