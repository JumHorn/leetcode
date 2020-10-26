#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string addStrings(string num1, string num2)
	{
		string res;
		int N1 = num1.length(), N2 = num2.length(), carry = 0;
		for (int i = N1 - 1, j = N2 - 1; i >= 0 || j >= 0 || carry > 0;)
		{
			if (i >= 0)
				carry += num1[i--] - '0';
			if (j >= 0)
				carry += num2[j--] - '0';
			res.push_back(carry % 10 + '0');
			carry /= 10;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};