#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
	{
		int N = queries.size(), len = nums[0].size();
		for (int i = 0; i < N; ++i)
			queries[i].push_back(i);
		vector<int> res(N);
		vector<pair<string, int>> v;
		for (int k = 0; k < nums.size(); ++k)
			v.push_back({nums[k], k});

		sort(queries.begin(), queries.end());
		for (int i = 0, j = 0; j < N; i = j)
		{
			while (j < N && queries[i][1] == queries[j][1])
				++j;
			int trim = queries[i][1];
			sort(v.begin(), v.end(), [&](pair<string, int> &lhs, pair<string, int> &rhs)
				 {
					 int diff = lhs.first.compare(len - trim, trim, rhs.first, len - trim);
					 if (diff == 0)
						 return lhs.second < rhs.second;
					 return diff < 0;
				 });
			for (int k = i; k < j; ++k)
			{
				int a = queries[k][0], c = queries[k][2];
				res[c] = v[a - 1].second;
			}
		}
		return res;
	}
};