#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries)
	{
		int N = queries.size();
		vector<int> res(N, -1);
		for (int i = 0; i < N; ++i)
			queries[i].push_back(i);
		auto f = [](vector<int> &lhs, vector<int> &rhs) {
			return lhs[1] > rhs[1];
		};
		sort(queries.begin(), queries.end(), f);
		sort(rooms.begin(), rooms.end(), f);
		set<int> id;
		for (int i = 0, j = 0; i < N; ++i)
		{
			for (; j < (int)rooms.size() && rooms[j][1] >= queries[i][1]; ++j)
				id.insert(rooms[j][0]);
			auto iter = id.lower_bound(queries[i][0]);
			int diff = 0;
			if (iter != id.end())
			{
				diff = *iter - queries[i][0];
				res[queries[i][2]] = *iter;
			}
			if (iter != id.begin())
			{
				--iter;
				if (res[queries[i][2]] == -1 || queries[i][0] - *iter <= diff)
					res[queries[i][2]] = *iter;
			}
		}
		return res;
	}
};