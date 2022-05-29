#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int rearrangeCharacters(string s, string target)
	{
		vector<int> count1(26), count2(26);
		for (auto c : s)
			++count1[c - 'a'];
		for (auto c : target)
			++count2[c - 'a'];
		int res = INT_MAX;
		for (int i = 0; i < 26; ++i)
		{
			if (count2[i] == 0)
				continue;
			res = min(res, count1[i] / count2[i]);
		}
		return res;
	}
};