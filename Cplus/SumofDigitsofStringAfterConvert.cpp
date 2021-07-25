#include <string>
using namespace std;

class Solution
{
public:
	int getLucky(string s, int k)
	{
		int n = 0;
		for (auto c : s)
		{
			int val = c - 'a' + 1;
			n += val % 10;
			n += val / 10;
		}
		int res = n;
		for (int i = 0; i < k - 1; ++i)
		{
			res = add(res);
		}
		return res;
	}

	int add(int n)
	{
		int res = 0;
		while (n != 0)
		{
			res += n % 10;
			n /= 10;
		}
		return res;
	}
};