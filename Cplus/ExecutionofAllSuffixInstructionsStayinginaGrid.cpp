#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> executeInstructions(int n, vector<int> &startPos, string s)
	{
		vector<int> res;
		int m = s.length();
		for (int i = 0; i < m; ++i)
		{
			int j = i, x = startPos[1], y = startPos[0];
			for (; j < m; ++j)
			{
				if (s[j] == 'L')
					--x;
				else if (s[j] == 'R')
					++x;
				else if (s[j] == 'U')
					--y;
				else
					++y;
				if (x < 0 || x >= n || y < 0 || y >= n)
					break;
			}
			res.push_back(j - i);
		}
		return res;
	}
};