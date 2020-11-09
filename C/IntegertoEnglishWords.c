#include <stdio.h>
#include <string.h>

static const char *LESS_THAN_20[] = {"", "One", "Two", "Three", "Four", "Five", "Six",
									 "Seven", "Eight", "Nine", "Ten", "Eleven",
									 "Twelve", "Thirteen", "Fourteen", "Fifteen",
									 "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

static const char *TENS[] = {"", "Ten", "Twenty", "Thirty", "Forty",
							 "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

static const char *THOUSANDS[] = {"", "Thousand", "Million", "Billion"};

typedef struct string
{
	char data[350];
} string;

string thousand(int num)
{
	string res = {""};
	if (num == 0)
		return res;
	if (num < 20)
		sprintf(res.data, "%s ", LESS_THAN_20[num]);
	else if (num < 100)
		sprintf(res.data, "%s %s", TENS[num / 10], thousand(num % 10).data);
	else
		sprintf(res.data, "%s Hundred %s", LESS_THAN_20[num / 100], thousand(num % 100).data);
	return res;
}

char *numberToWords(int num)
{
	if (num == 0)
		return "Zero";
	string words = {""};
	int N = 0;
	for (int i = 0; num > 0; ++i, num /= 1000)
	{
		if (num % 1000 != 0)
		{
			string data = {""};
			N = sprintf(data.data, "%s%s %s", thousand(num % 1000).data, THOUSANDS[i], words.data);
			words = data;
		}
	}
	while (words.data[N - 1] == ' ')
		--N;
	words.data[N] = '\0';
	return strdup(words.data);
}