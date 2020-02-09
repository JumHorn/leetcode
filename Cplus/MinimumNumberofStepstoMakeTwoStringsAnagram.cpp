#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSteps(string s, string t)
	{
		vector<int> v(26);
		for (int i = 0; i < (int)s.length(); i++)
		{
			++v[s[i] - 'a'];
			--v[t[i] - 'a'];
		}
		int positive = 0, negative = 0;
		for (int i = 0; i < 26; i++)
		{
			if (v[i] >= 0)
				positive += v[i];
			else
				negative += v[i];
		}
		return min(positive, negative) + abs(positive - negative);
	}
};
