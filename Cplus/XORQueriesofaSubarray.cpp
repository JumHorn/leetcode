#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
	{
		int N = arr.size(), Q = queries.size();
		vector<int> prefix(N + 1), res(Q);
		for (int i = 0; i < N; ++i)
			prefix[i + 1] = (prefix[i] ^ arr[i]);
		for (int i = 0; i < Q; ++i)
			res[i] = (prefix[queries[i][0]] ^ prefix[queries[i][1] + 1]);
		return res;
	}
};