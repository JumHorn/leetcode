#include <string>
using namespace std;

class Solution
{
public:
	int numSub(string s)
	{
		int n = s.length();
		long res = 0;
		for (int i = 0, j = 0; i < n;)
		{
			while (i < n && s[i] == '0')
				++i;
			j = i;
			while (j < n && s[j] == '1')
				++j;
			long len = j - i;
			res = (res + len * (len + 1) / 2) % MOD;
			i = j + 1;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};
