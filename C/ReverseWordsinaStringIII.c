
void reverse(char *arr, int first, int last)
{
	while (first < last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
		++first;
		--last;
	}
}

char *reverseWords(char *s)
{
	int i = 0, j = 0;
	for (; s[i]; ++i)
	{
		if (s[i] == ' ')
		{
			reverse(s, j, i - 1);
			j = i + 1;
		}
	}
	reverse(s, j, i - 1);
	return s;
}