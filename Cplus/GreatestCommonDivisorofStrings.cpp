#include <string>
using namespace std;

class Solution
{
public:
	string gcdOfStrings(string str1, string str2)
	{
		int N1 = str1.length(), N2 = str2.length();
		for (int i = gcd(N1, N2); i > 0; --i)
		{
			if (divide(str1, str1.substr(0, i)) && divide(str2, str1.substr(0, i)))
			{
				return str1.substr(0, i);
			}
		}
		return "";
	}

	int gcd(int x, int y) const
	{
		if (x == 0)
			return y;
		return gcd(y % x, x);
	}

	bool divide(const string &p, const string &q) //p/q
	{
		int N = q.length();
		for (int i = 0; i < (int)p.length(); ++i)
		{
			if (p[i] != q[i % N])
				return false;
		}
		return true;
	}
};