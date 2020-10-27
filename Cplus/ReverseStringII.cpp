#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string reverseStr(string s, int k)
	{
		int N = s.length(), i = 0;
		for (; i + k < N; i += 2 * k)
			reverse(s.begin() + i, s.begin() + i + k);
		reverse(s.begin() + i, s.end());
		return s;
	}
};