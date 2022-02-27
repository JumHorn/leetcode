#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSteps(string s, string t)
	{
		vector<int> count1(26), count2(26);
		for (auto c : s)
			++count1[c - 'a'];
		for (auto c : t)
			++count2[c - 'a'];
		int res = 0;
		for (int i = 0; i < 26; ++i)
			res += abs(count1[i] - count2[i]);
		return res;
	}
};