#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> partitionLabels(string S)
	{
		int N = S.length();
		vector<int> lastpos(26);
		for (int i = 0; i < N; ++i)
			lastpos[S[i] - 'a'] = i;
		vector<int> res;
		for (int i = 0, j = 0; i < N; ++i)
		{
			j = max(j, lastpos[S[i] - 'a']);
			if (i == j)
				res.push_back(i + 1);
		}
		for (int i = res.size() - 1; i > 0; --i)
			res[i] -= res[i - 1];
		return res;
	}
};