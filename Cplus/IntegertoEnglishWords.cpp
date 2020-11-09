#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution()
	{
		LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six",
						"Seven", "Eight", "Nine", "Ten", "Eleven",
						"Twelve", "Thirteen", "Fourteen", "Fifteen",
						"Sixteen", "Seventeen", "Eighteen", "Nineteen"};

		TENS = {"", "Ten", "Twenty", "Thirty", "Forty",
				"Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

		THOUSANDS = {"", "Thousand", "Million", "Billion"};
	}

	string numberToWords(int num)
	{
		if (num == 0)
			return "Zero";
		string words;
		for (int i = 0; num > 0; ++i, num /= 1000)
		{
			if (num % 1000 != 0)
				words = thousand(num % 1000) + THOUSANDS[i] + " " + words;
		}
		int N = words.length(); //words trim
		while (words[N - 1] == ' ')
			--N;
		return words.substr(0, N);
	}

	string thousand(int num)
	{
		if (num == 0)
			return "";
		if (num < 20)
			return LESS_THAN_20[num] + " ";
		if (num < 100)
			return TENS[num / 10] + " " + thousand(num % 10);
		return LESS_THAN_20[num / 100] + " Hundred " + thousand(num % 100);
	}

private:
	vector<string> LESS_THAN_20;
	vector<string> TENS;
	vector<string> THOUSANDS;
};