#include <stdio.h>
#include <stdlib.h>

char *countAndSay(int n)
{
	if (n == 1)
		return "1";
	char data[5000] = {0};
	char *res = (char *)malloc(sizeof(char *) * 5000);
	sprintf(res, "%d", 1);
	for (int i = 2; i <= n; ++i)
	{
		strcpy(data, res);
		char pre = -1;
		int count = 0, resSize = 0;
		for (int j = 0; data[j]; ++j)
		{
			if (pre != data[j])
			{
				if (count != 0)
					resSize += sprintf(&res[resSize], "%d%c", count, pre);
				pre = data[j];
				count = 1;
			}
			else
				++count;
		}
		sprintf(&res[resSize], "%d%c", count, pre);
	}
	return res;
}