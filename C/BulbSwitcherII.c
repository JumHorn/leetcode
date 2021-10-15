
#define min(a, b) (((a) < (b)) ? (a) : (b))

int flipLights(int n, int m)
{
	n = min(n, 3);
	if (m == 0)
		return 1;
	if (m == 1)
		return n + 1;
	if (m == 2)
		return n <= 2 ? (1 << n) : 7;
	return 1 << n;
}