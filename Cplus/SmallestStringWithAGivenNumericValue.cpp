#include <string>
using namespace std;

class Solution
{
public:
	string getSmallestString(int n, int k)
	{
		string res(n, 'a');
		k -= n;
		for (int i = n - 1; i >= 0 && k > 0; --i)
		{
			res[i] += min(k, 25);
			k -= min(k, 25);
		}
		return res;
	}
};