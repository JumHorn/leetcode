#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	typedef pair<unordered_set<int>, int> Info;
	vector<int> smallestMissingValueSubtree(vector<int> &parents, vector<int> &nums)
	{
		int N = parents.size();
		vector<vector<int>> graph(N);
		for (int i = 1; i < N; ++i)
			graph[parents[i]].push_back(i);
		vector<int> res(N);
		postorder(graph, nums, 0, res);
		return res;
	}
	// {{numbers in subtree},base}
	Info postorder(vector<vector<int>> &graph, vector<int> &nums, int cur, vector<int> &res)
	{
		Info info;
		info.second = 1;
		info.first.insert(nums[cur]);

		for (auto to : graph[cur])
		{
			auto data = postorder(graph, nums, to, res);
			merge(info, data);
		}

		while (info.first.count(info.second))
			++info.second;
		res[cur] = info.second;
		return move(info);
	}

	// merge rhs to lhs
	void merge(Info &lhs, Info &rhs)
	{
		if (lhs.first.size() < rhs.first.size()) //very important
			swap(lhs, rhs);
		lhs.second = max(lhs.second, rhs.second);
		for (auto n : rhs.first)
			lhs.first.insert(n);
	}
};