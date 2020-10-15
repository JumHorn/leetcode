#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *lhs, int *rhs)
{
	int tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

char *largestTimeFromDigits(int *arr, int arrSize)
{
	int maxhour = -1, maxminute = -1;
	for (int i = 0; i < 4; ++i)
	{
		swap(&arr[0], &arr[i]);
		for (int j = 1; j < 4; ++j)
		{
			swap(&arr[1], &arr[j]);
			int hour = arr[0] * 10 + arr[1];
			if (hour < 24)
			{
				for (int k = 2; k < 4; ++k)
				{
					swap(&arr[2], &arr[k]);
					int minute = arr[2] * 10 + arr[3];
					if (minute < 59)
					{
						if ((hour > maxhour) || (hour == maxhour && minute > maxminute))
						{
							maxhour = hour;
							maxminute = minute;
						}
					}
					swap(&arr[2], &arr[k]);
				}
			}
			swap(&arr[1], &arr[j]);
		}
		swap(&arr[0], &arr[i]);
	}
	if (maxhour < 0)
		return "";
	char *res = (char *)malloc(sizeof(char) * 6);
	res[5] = '\0';
	sprintf(res, "%02d:%02d", maxhour, maxminute);
	return res;
}