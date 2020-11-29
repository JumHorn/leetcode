#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
	{
		vector<bool> res;
		int N = s.length();
		vector<int> prefixsum(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = (prefixsum[i] ^ (1 << (s[i] - 'a')));

		for (auto &query : queries)
		{
			int r = bitCount(prefixsum[query[1] + 1] ^ prefixsum[query[0]]);
			res.push_back(query[2] >= (r >> 1));
		}
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};