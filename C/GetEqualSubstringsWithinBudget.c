#define max(a, b) (((a) > (b)) ? (a) : (b))
#define abs(a) (((a) < 0) ? (-(a)) : (a))

int equalSubstring(char *s, char *t, int maxCost)
{
	int i = 0, j = 0, res = 0, sum = 0;
	while (s[i])
	{
		sum += abs(s[i] - t[i]);
		if (sum <= maxCost)
			res = max(res, i - j + 1);
		else
		{
			while (j <= i)
			{
				sum -= abs(s[j] - t[j]);
				j++;
				if (sum <= maxCost)
					break;
			}
		}
		i++;
	}
	return res;
}