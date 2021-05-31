#include <string>
using namespace std;

class Solution
{
public:
	string maxValue(string n, int x)
	{
		string res;
		int N = n.length(), i = 0;
		if (n[0] == '-')
		{
			res.push_back('-');
			for (i = 1; i < N && n[i] - '0' <= x; ++i)
				res.push_back(n[i]);
		}
		else
		{
			for (; i < N && n[i] - '0' >= x; ++i)
				res.push_back(n[i]);
		}
		res.push_back(x + '0');
		for (; i < N; ++i)
			res.push_back(n[i]);
		return res;
	}
};