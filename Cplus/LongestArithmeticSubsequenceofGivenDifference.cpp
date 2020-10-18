#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestSubsequence(vector<int> &arr, int difference)
	{
		int res = 0;
		unordered_map<int, int> m; //{value,length}
		for (auto n : arr)
		{
			m[n] = m[n - difference] + 1;
			res = max(res, m[n]);
		}
		return res;
	}
};