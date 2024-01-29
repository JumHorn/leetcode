#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumLength(vector<int> &nums)
	{
		unordered_map<int, int> m; //{val,count}
		for (auto n : nums)
			++m[n];
		int res = 1;
		if (m.count(1) != 0)
			res = (m[1] - 1) / 2 * 2 + 1;
		vector<int> k = {1}; //{1,2,4,8,16}
		for (int i = 0; i < 4; ++i)
			k.push_back(k.back() << 1);
		for (auto &[n, count] : m)
		{
			long long val = n;
			if (val > 1 && count >= 2)
			{
				int len = 1;
				for (int i = 1; i <= 4; ++i)
				{
					long long powval = pow(val, k[i]);
					if (powval > 1e9)
						break;
					auto it = m.find(powval);
					if (it == m.end())
						break;
					if (it->second <= 1)
					{
						if (it->second == 1)
							len += 2;
						break;
					}
					len += 2;
				}
				res = max(res, len);
			}
		}
		return res;
	}
};