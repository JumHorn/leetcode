
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int hIndex(int *citations, int citationsSize)
{
	int res = 0;
	for (int i = citationsSize - 1; i >= 0; i--)
		res = max(res, min(citations[i], citationsSize - i));
	return res;
}