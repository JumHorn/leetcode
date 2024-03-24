#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumLengthSubstring(string s)
	{
		int N = s.size(), res = 0;
		vector<int> count(26);
		for (int i = 0, j = 0; i < N; ++i)
		{
			int index = s[i] - 'a';
			++count[index];
			for (; count[index] > 2; ++j)
				--count[s[j] - 'a'];
			res = max(res, i - j + 1);
		}
		return res;
	}
};