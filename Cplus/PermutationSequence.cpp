#include <string>
using namespace std;

class Solution
{
public:
	string getPermutation(int n, int k)
	{
		string res = string("123456789").substr(0, n);
		int f = factorial(n);
		--k; //become zero index
		for (int i = 0; i < n; ++i)
		{
			f /= n - i;
			int j = i + k / f; // calculate index of char to put at s[i]
			k %= f;
			char c = res[j];
			// remove c by shifting to cover up (adjust the right part).
			for (; j > i; --j)
				res[j] = res[j - 1];
			res[i] = c;
		}
		return res;
	}

	int factorial(int n)
	{
		if (n < 2)
			return n;
		return factorial(n - 1) * n;
	}
};