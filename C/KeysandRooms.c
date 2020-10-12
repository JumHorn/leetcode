#include <stdbool.h>
#include <string.h>

void dfs(int** rooms, int roomsSize, int* roomsColSize, int index, int* seen)
{
	if (seen[index])
		return;
	seen[index] = true;
	for (int i = 0; i < roomsColSize[index]; ++i)
		dfs(rooms, roomsSize, roomsColSize, rooms[index][i], seen);
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize)
{
	int seen[roomsSize];
	memset(seen, 0, sizeof(seen));
	dfs(rooms, roomsSize, roomsColSize, 0, seen);
	for (int i = 0; i < roomsSize; ++i)
	{
		if (seen[i] == 0)
			return false;
	}
	return true;
}
