#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		string res;
		int carry = 0;
		for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0 || carry > 0;)
		{
			if (i >= 0)
				carry += a[i--] - '0';
			if (j >= 0)
				carry += b[j--] - '0';
			res.push_back(carry % 2 + '0');
			carry /= 2;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};