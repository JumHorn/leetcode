#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string repeatLimitedString(string s, int repeatLimit)
	{
		vector<int> count(26);
		for (auto c : s)
			++count[c - 'a'];
		string res;
		for (int i = 25, j = 24; j >= 0;)
		{
			while (i >= 0 && count[i] <= 0)
				--i;
			j = i - 1;
			while (j >= 0 && count[j] <= 0)
				--j;
			if (i < 0)
				break;
			if (count[i] > 0)
			{
				if (count[i] >= repeatLimit)
				{
					res += string(repeatLimit, 'a' + i);
					count[i] -= repeatLimit;
					if (count[i] > 0)
					{
						if (j < 0 || count[j] <= 0)
							break;
						res.push_back(j + 'a');
						--count[j];
					}
				}
				else
				{
					res += string(count[i], 'a' + i);
					count[i] = 0;
				}
			}
		}
		return res;
	}
};