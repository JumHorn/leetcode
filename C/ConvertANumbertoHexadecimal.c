
void reverse(char *arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

char *toHex(int num)
{
	const char *HEX = "0123456789abcdef";
	unsigned int N = num;
	if (N == 0)
		return "0";
	char *res = (char *)malloc(sizeof(char) * 9);
	int resSize = 0;
	while (N != 0)
	{
		res[resSize++] = HEX[N & 0b1111]; //N%16
		N >>= 4;						  //N/=16
	}
	res[resSize] = '\0';
	reverse(res, 0, resSize - 1);
	return res;
}