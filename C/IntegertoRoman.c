#include <stdlib.h>
#include <string.h>

char *intToRoman(int num)
{
	char *M[] = {"", "M", "MM", "MMM"};
	char *C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	char *X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	char *I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	char *res = (char *)malloc(sizeof(char) * 17);
	memset(res, 0, sizeof(char) * 17);
	strcat(res, M[num / 1000]);
	strcat(res, C[(num % 1000) / 100]);
	strcat(res, X[(num % 100) / 10]);
	strcat(res, I[num % 10]);
	return res;
}