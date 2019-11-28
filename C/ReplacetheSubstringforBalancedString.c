/*
Q 1
R 2
E 3
W 0
*/
#define HASH(x) (((x) % 7) - 3)

int balancedString(char *s)
{
	char *p = s;
	int map[4] = {0}, len = 0;
	while (*p)
	{
		map[HASH(*p)]++;
		len++;
		p++;
	}
	int lo = 0, hi = len / 4 * 3, mi, avg = len / 4;
	for (int i = 0; i < 4; i++)
		if (map[i] > avg)
			lo += map[i] - avg;
	while (lo < hi)
	{
		mi = (hi - lo) / 2 + lo;
		int arr[4] = {map[0], map[1], map[2], map[3]};
		for (int i = 0; i < mi; i++)
			arr[HASH(s[i])]--;
		bool flag = true;
		int i = mi - 1;
		while (true)
		{
			int balance = 0;
			for (int j = 0; j < 4; j++)
				if (arr[j] < avg)
					balance += avg - arr[j];
			if (balance == mi)
			{
				flag = false;
				break;
			}
			if (++i >= len)
				break;
			arr[HASH(s[i])]--;
			arr[HASH(s[i - mi])]++;
		}
		if (flag)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}