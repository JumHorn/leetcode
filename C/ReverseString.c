
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

void reverseString(char* s, int sSize)
{
	int i = -1, j = sSize;
	while (++i < --j)
		swap(s[i], s[j]);
}
