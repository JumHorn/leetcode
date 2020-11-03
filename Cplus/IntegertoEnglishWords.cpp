#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
	unordered_map<int, string> radix;

public:
	Solution()
	{
		radix[0] = "Zero";
		radix[1] = "One";
		radix[2] = "Two";
		radix[3] = "Three";
		radix[4] = "Four";
		radix[5] = "Five";
		radix[6] = "Six";
		radix[7] = "Seven";
		radix[8] = "Eight";
		radix[9] = "Nine";
		radix[10] = "Ten";
		radix[11] = "Eleven";
		radix[12] = "Twelve";
		radix[13] = "Thirteen";
		radix[14] = "Fourteen";
		radix[15] = "Fifteen";
		radix[16] = "Sixteen";
		radix[17] = "Seventeen";
		radix[18] = "Eighteen";
		radix[19] = "Nineteen";

		radix[20] = "Twenty";
		radix[30] = "Thirty";
		radix[40] = "Forty";
		radix[50] = "Fifty";
		radix[60] = "Sixty";
		radix[70] = "Seventy";
		radix[80] = "Eighty";
		radix[90] = "Ninety";
		radix[100] = "Hundred";

		radix[1000] = "Thousand";
		radix[1000000] = "Million";
		radix[1000000000] = "Billion";
	}

	string numberToWords(int num)
	{
		if (num == 0)
			return radix[num];
		string res;
		int base = 1000000000;
		for (int i = 0; i < 4; ++i)
		{
			int tmp = num / base;
			if (tmp != 0)
			{
				if (base != 1)
					res += " " + numberToStr(tmp) + " " + radix[base];
				else
					res += " " + numberToStr(tmp);
			}
			num %= base;
			base /= 1000;
		}
		return res.substr(1);
	}

	string numberToStr(int num)
	{
		string res;
		int base = 100;
		int tmp = num / base;
		if (tmp > 0)
			res += " " + radix[tmp] + " " + radix[base];
		tmp = num % base;
		if (tmp > 0 && tmp <= 20)
		{
			res += " " + radix[tmp];
			return res.substr(1);
		}
		base /= 10;
		if (tmp / base > 0)
			res += " " + radix[tmp / base * 10];
		tmp %= base;
		if (tmp > 0)
			res += " " + radix[tmp];
		return res.substr(1);
	}
};