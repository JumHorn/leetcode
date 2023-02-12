#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries)
	{
		int N = queries.size();
		vector<vector<int>> res(N);
		vector<unordered_map<int, vector<int>>> len(32); //{val,index}
		for (int i = 0; i < N; ++i)
		{
			int val = (queries[i][0] ^ queries[i][1]);
			len[leftMostBit(val)][val].push_back(i);
		}

		for (int l = 1; l < 32; ++l)
		{
			int mask = ((1u << l) - 1);
			if (len[l].empty())
				continue;
			long long i = 0, val = 0;
			for (; i < l; ++i)
				val = ((val << 1) | (s[i] - '0'));
			for (auto index : len[l][val])
				res[index] = {0, l - 1};
			len[l].erase(val);
			for (; i < s.size(); ++i)
			{
				val = ((((val << 1) | (s[i] - '0'))) & mask);
				for (auto index : len[l][val])
					res[index] = {(int)i - l + 1, (int)i};
				len[l].erase(val);
			}
		}
		for (auto &v : res)
		{
			if (v.empty())
				v = {-1, -1};
		}
		return res;
	}

	int leftMostBit(int n)
	{
		int res = 31;
		while (res > 0 && ((n >> res) & 1) == 0)
			--res;
		return res + 1;
	}
};