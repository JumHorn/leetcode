#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> largeGroupPositions(string s)
	{
		vector<vector<int>> res;
		int N = s.length();
		for (int i = 0, j = 0; i <= N; ++i)
		{
			if (i == N || s[i] != s[j])
			{
				if (i - j >= 3)
					res.push_back({j, i - 1});
				j = i;
			}
		}
		return res;
	}
};