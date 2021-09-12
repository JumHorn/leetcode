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
		Info info;
		postorder(graph, nums, 0, info, res);
		return res;
	}
	// {{numbers in subtree},base}
	void postorder(vector<vector<int>> &graph, vector<int> &nums, int cur, Info &info, vector<int> &res)
	{
		info.second = 1;
		if (nums[cur] == 1)
			++info.second;
		else
			info.first.insert(nums[cur]);

		for (auto to : graph[cur])
		{
			Info data;
			postorder(graph, nums, to, data, res);
			merge(info, data);
		}
		res[cur] = info.second;
	}

	// merge rhs to lhs
	void merge(Info &lhs, Info &rhs)
	{
		if (lhs.first.size() < rhs.first.size()) //very important
			swap(lhs, rhs);
		lhs.second = max(lhs.second, rhs.second);
		for (auto n : rhs.first)
		{
			if (n >= lhs.second)
				lhs.first.insert(n);
		}
		while (lhs.first.find(lhs.second) != lhs.first.end())
			lhs.first.erase(lhs.second++);
	}
};