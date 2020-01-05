#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
	{
		vector<int> prefix(arr.size() + 1);
		vector<int> res(queries.size());
		for (int i = 0; i < (int)arr.size(); i++)
			prefix[i + 1] = (prefix[i] ^ arr[i]);
		for (int i = 0; i < (int)queries.size(); i++)
			res[i] = (prefix[queries[i][0]] ^ prefix[queries[i][1] + 1]);
		return res;
	}
};
