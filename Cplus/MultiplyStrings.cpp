#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		int N1 = num1.length(), N2 = num2.length();
		string res(N1 + N2, '0');
		for (int i = N1 - 1; i >= 0; --i)
		{
			for (int j = N2 - 1; j >= 0; --j)
			{
				int sum = (num1[i] - '0') * (num2[j] - '0') + (res[i + j + 1] - '0');
				res[i + j + 1] = sum % 10 + '0';
				res[i + j] += sum / 10;
			}
		}
		for (int i = 0; i < N1 + N2; ++i)
		{
			if (res[i] != '0')
				return res.substr(i);
		}
		return "0";
	}
};