
#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

void reverseString(char *s, int sSize)
{
	for (int i = 0, j = sSize - 1; i < j; ++i, --j)
		swap(s[i], s[j]);
}