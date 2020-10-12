#include <vector>
using namespace std;

class Solution
{
public:
	bool canVisitAllRooms(vector<vector<int>> &rooms)
	{
		vector<bool> seen(rooms.size());
		dfs(rooms, 0, seen);
		for (auto b : seen)
		{
			if (!b)
				return false;
		}
		return true;
	}

	void dfs(vector<vector<int>> &rooms, int index, vector<bool> &seen)
	{
		if (seen[index])
			return;
		seen[index] = true;
		for (auto &room : rooms[index])
			dfs(rooms, room, seen);
	}
};