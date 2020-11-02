#include <string.h>

int minOperations(char** logs, int logsSize)
{
	int res = 0;
	for (int i = 0; i < logsSize; ++i)
	{
		if (strcmp(logs[i], "./") == 0)
		{
		}
		else if (strcmp(logs[i], "../") == 0)
		{
			if (res > 0)
				--res;
		}
		else
			++res;
	}
	return res;
}
