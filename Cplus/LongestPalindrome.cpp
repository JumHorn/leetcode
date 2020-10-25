#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestPalindrome(string s)
	{
		vector<int> count('z' - 'A' + 1);
		int res = 0, N = s.length();
		for (auto c : s)
		{
			if (++count[c - 'A'] == 2)
			{
				count[c - 'A'] = 0;
				res += 2;
			}
		}
		if (N % 2 == 0)
			res += (res == N ? 0 : 1);
		return res + N % 2;
	}
};