#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProduct(vector<string> &words)
	{
		int N = words.size(), res = 0;
		vector<int> mask(N);
		for (int i = 0; i < N; ++i)
		{
			for (auto c : words[i])
				mask[i] |= 1 << (c - 'a');
			for (int j = 0; j < i; ++j)
			{
				if ((mask[i] & mask[j]) == 0)
					res = max(res, (int)words[i].length() * (int)words[j].length());
			}
		}
		return res;
	}
};