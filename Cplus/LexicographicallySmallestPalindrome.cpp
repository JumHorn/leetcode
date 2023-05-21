#include <string>
using namespace std;

class Solution
{
public:
	string makeSmallestPalindrome(string s)
	{
		int N = s.size();
		for (int i = 0, j = N - 1; i < j; ++i, --j)
			s[i] = s[j] = min(s[i], s[j]);
		return s;
	}
};