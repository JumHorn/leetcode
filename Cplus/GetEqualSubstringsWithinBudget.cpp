#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int equalSubstring(string s, string t, int maxCost)
	{
		vector<int> v(s.length());
		for (int i = 0; i < (int)s.length(); i++)
			v[i] = abs(s[i] - t[i]);
		int len = s.length(), res = 0, sum = 0;
		for (int i = 0, j = 0; i < len; i++)
		{
			sum += v[i];
			if (sum <= maxCost)
				res = max(res, i - j + 1);
			else
			{
				while (j <= i)
				{
					sum -= v[j++];
					if (sum <= maxCost)
						break;
				}
			}
		}
		return res;
	}
};