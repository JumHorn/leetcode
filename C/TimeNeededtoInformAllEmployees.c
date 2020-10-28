#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int dfs(int id, int* manager, int* informTime, int* time)
{
	if (id == -1)
		return 0;
	if (time[id] != -1)
		return time[id];
	return time[id] = informTime[id] + dfs(manager[id], manager, informTime, time);
}

int numOfMinutes(int n, int headID, int* manager, int managerSize, int* informTime, int informTimeSize)
{
	int time[managerSize], res = 0;
	memset(time, -1, sizeof(time));
	for (int i = 0; i < managerSize; ++i)
	{
		if (time[i] == -1)
			dfs(i, manager, informTime, time);
		res = max(res, time[i]);
	}
	return res;
}
