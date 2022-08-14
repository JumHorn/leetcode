#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int edgeScore(vector<int> &edges)
	{
		int N = edges.size();
		vector<long> indegree(N);
		for (int i = 0; i < N; ++i)
			indegree[edges[i]] += i;
		return max_element(indegree.begin(), indegree.end()) - indegree.begin();
	}
};