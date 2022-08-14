#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string smallestNumber(string pattern)
	{
		int N = pattern.size();
		string res = string("123456789").substr(0, N + 1);
		while (next_permutation(res.begin(), res.end()))
		{
			if (checkValid(pattern, res))
				break;
		}
		return res;
	}

	bool checkValid(string &pattern, string &num)
	{
		for (int i = 0; i < (int)pattern.size(); ++i)
		{
			if ((pattern[i] == 'I') != (num[i + 1] > num[i]))
				return false;
		}
		return true;
	}
};