#include <stdlib.h>
#include <string.h>

char* originalDigits(char* s)
{
	int map[26] = {0}, count[10] = {0};  //the count of each digits in s
	char* number[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char* digits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	char even[] = {'z', 'w', 'u', 'x', 'g'};  //only char 0 2 4 6 8
	char odd[] = {'o', 'h', 'f', 's'};		  //only char 1 3 5 7
	for (int i = 0; s[i]; ++i)
		++map[s[i] - 'a'];
	for (int i = 0; i < 5; i++)
	{
		count[2 * i] = map[even[i] - 'a'];
		int size = strlen(number[2 * i]);
		for (int j = 0; j < size; ++j)
			map[number[2 * i][j] - 'a'] -= count[2 * i];
	}
	for (int i = 0; i < 4; i++)
	{
		count[2 * i + 1] = map[odd[i] - 'a'];
		int size = strlen(number[2 * i + 1]);
		for (int j = 0; j < size; ++j)
			map[number[2 * i + 1][j] - 'a'] -= count[2 * i + 1];
	}
	count[9] = map['i' - 'a'];
	char* res = (char*)malloc(sizeof(char) * 50000);
	res[0] = '\0';
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < count[i]; ++j)
			strcat(res, digits[i]);
	}
	return res;
}
