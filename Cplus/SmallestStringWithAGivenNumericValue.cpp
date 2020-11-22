#include <string>
using namespace std;

class Solution
{
public:
	string getSmallestString(int n, int k)
	{
		string res(n, 'a');
		for (int i = 0; i < n; ++i)
		{
			for (char c = 'a'; c <= 'z'; ++c)
			{
				if (k - (c - 'a' + 1) <= ('z' - 'a' + 1) * (n - i - 1))
				{
					res[i] = c;
					k -= (c - 'a' + 1);
					break;
				}
			}
		}
		return res;
	}
};