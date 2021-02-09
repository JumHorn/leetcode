#include <string.h>

#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

void reverse(char* arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

int maximumGain(char* s, int x, int y)
{
	int N = strlen(s);
	if (x > y)
	{
		reverse(s, 0, N - 1);
		swap(x, y);
	}
	int res = 0, top = -1;
	char stack[N];
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == 'a' && top != -1 && stack[top] == 'b')	//ba
		{
			--top;
			res += y;
		}
		else
			stack[++top] = s[i];
	}
	// process ab with in-place stack
	++top;
	for (int end = top, i = end - 1; i >= 0; --i)
	{
		if (stack[i] == 'a' && top != end && stack[top] == 'b')
		{
			++top;
			res += x;
		}
		else
			stack[--top] = stack[i];
	}
	return res;
}
