#include <limits.h>
#include <stdbool.h>
#include <string.h>

/*
题目意思是在任意位置先oddjump再evenjump看是否能到达终点
两次理解都出错，故删除该问题
*/

int oddEvenJumps(int *A, int ASize)
{
	int jumps[ASize], smallindex = ASize - 1, largeindex = ASize - 1;
	for (int i = ASize - 1; i >= 0; --i)
	{
		if ((i & 1) == 0) //odd (1 based index)
		{
			if (A[i] <= A[smallindex])
			{
				jumps[i] = smallindex;
				smallindex = i;
			}
			else
			{
				if (A[i] >= A[largeindex])
				{
					largeindex = i;
					jumps[i] = i;
				}
				else
				{
					int k = ASize - 1;
					for (int j = ASize - 1; j > i; --j)
					{
						if (A[i] <= A[j] && A[k] >= A[j])
							k = j;
					}
					jumps[i] = k;
				}
			}
		}
		else //even
		{
			if (A[i] >= A[largeindex])
			{
				jumps[i] = largeindex;
				largeindex = i;
			}
			else
			{
				if (A[i] <= A[smallindex])
				{
					smallindex = i;
					jumps[i] = i;
				}
				else
				{
					int k = ASize - 1;
					for (int j = ASize - 1; j > i; --j)
					{
						if (A[i] >= A[j] && A[k] <= A[j])
							k = j;
					}
					jumps[i] = k;
				}
			}
		}
	}

	int res = 1;
	bool reachEnd[ASize];
	memset(reachEnd, 0, sizeof(reachEnd));
	reachEnd[ASize - 1] = true;
	for (int i = ASize - 2; i >= 0; --i)
	{
		reachEnd[i] = reachEnd[jumps[i]];
		if (reachEnd[i])
			++res;
	}
	return res;
}