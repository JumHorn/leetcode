#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool checkInclusion(string s1, string s2)
	{
		int N = s1.length();
		vector<int> count1(26), count2(26);
		if (N > (int)s2.length())
			return false;
		for (int i = 0; i < N; ++i)
		{
			++count1[s1[i] - 'a'];
			++count2[s2[i] - 'a'];
		}
		if (count1 == count2)
			return true;
		for (int i = N; i < (int)s2.length(); ++i)
		{
			++count2[s2[i] - 'a'];
			--count2[s2[i - N] - 'a'];
			if (count1 == count2)
				return true;
		}
		return false;
	}
};