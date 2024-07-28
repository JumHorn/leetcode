#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfSubstrings(string s)
	{
		int res = 0, N = s.size();
		vector<int> pos = {-1};
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == '0')
				pos.push_back(i);
			res += i - pos.back(); // 枚举从i向前0个'0'
			for (int cnt0 = 1; cnt0 * cnt0 <= i + 1 - cnt0 && cnt0 < pos.size(); ++cnt0)
			{
				int k = pos.size() - cnt0, p = pos[k], q = pos[k - 1], cnt1 = i - p - (cnt0 - 1); // number of '1' in [p,i]
				int d = max(cnt0 * cnt0 - cnt1, 0);
				res += max(p - q - d, 0);
			}
		}
		return res;
	}
};