#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxChunksToSorted(vector<int> &arr)
	{
		vector<int> dup = arr;
		sort(dup.begin(), dup.end());
		unordered_map<int, int> m;
		const int N = arr.size();
		for (int i = N - 1; i >= 0; --i)
			m[dup[i]] = i;
		int res = 0;
		for (int i = 0, j = 0; i < N; i++)
		{
			j = max(j, m[arr[i]]);
			if (i == j)
				++res;
		}
		return res;
	}
};