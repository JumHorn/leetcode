#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &nums)
	{
		int N = parents.size();
		vector<vector<int>> graph(N);
		for (int i = 0; i < N; ++i)
		{
			if (parents[i] != -1)
				graph[parents[i]].push_back(i);
		}
		vector<int> res(N);
		postorder(graph, 0, -1, nums, res);
		return res;
	}
	// {{numbers in subtree},base}
	const pair<set<int>, int> postorder(vector<vector<int>> &graph, int at, int from, vector<int> &nums, vector<int> &res)
	{
		pair<set<int>, int> data;
		data.first.insert(nums[at]);
		data.second = 1;
		for (auto to : graph[at])
		{
			if (to != from)
			{
				auto &p = postorder(graph, to, at, nums, res);
				data.second = max(data.second, p.second);
				for (auto n : p.first)
					data.first.insert(n);
			}
		}
		auto iter = data.first.begin();
		while (iter != data.first.end() && *iter <= data.second)
		{
			auto tmp = iter;
			++iter;
			++data.second;
			data.first.erase(tmp);
		}
		res[at] = data.second;
		return data;
	}
};