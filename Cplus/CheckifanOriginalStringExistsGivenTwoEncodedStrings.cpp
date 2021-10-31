#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
not finished
*/

class Solution
{
public:
	bool possiblyEquals(string s1, string s2)
	{
		int M = s1.length(), N = s2.length();
		vector<vector<unordered_map<int, bool>>> dp(M, vector<unordered_map<int, bool>>(N));
		return memdp(s1, 0, s2, 0, 0, dp);
	}

	bool memdp(string &s1, int index1, string &s2, int index2, int diff, vector<vector<unordered_map<int, bool>>> &dp)
	{
		int M = s1.length(), N = s2.length();
		if (index1 >= M && index2 >= N)
			return diff == 0;
		if (diff == 0)
		{
		}
		else if (diff < 0)
		{
			if (index1 >= M)
				return false;
			if (isdigit(s1[index1]))
			{
			}
		}
		else
		{
		}
	}
};