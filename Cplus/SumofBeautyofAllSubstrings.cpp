#include <string>
using namespace std;

class Solution
{
public:
	int beautySum(string s)
	{
		int N = s.length(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			int count[26] = {0}, maxf = 1;
			for (int j = i; j < N; ++j)
			{
				++count[s[j] - 'a'];
				int minf = 500;
				for (int k = 0; k < 26; ++k)
				{
					if (count[k] != 0)
						minf = min(minf, count[k]);
				}
				maxf = max(maxf, count[s[j] - 'a']);
				res += maxf - minf;
			}
		}
		return res;
	}
};