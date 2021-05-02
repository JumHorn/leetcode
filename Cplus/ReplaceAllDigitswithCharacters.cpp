#include <string>
using namespace std;

class Solution
{
public:
	string replaceDigits(string s)
	{
		int N = s.length();
		for (int i = 1; i < N; i += 2)
			s[i] += s[i - 1] - '0';
		return s;
	}
};