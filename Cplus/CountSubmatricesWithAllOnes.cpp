#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int numSubmat(vector<vector<int>> &mat)
	{
		int M = mat.size(), N = mat[0].size(), res = 0;
		vector<int> height(N);
		for (int i = 0; i < M; ++i)
		{
			stack<pair<int, int>> s; //{index,count of submat} increasing stack
			for (int j = 0; j < N; ++j)
			{
				height[j] = mat[i][j] == 0 ? 0 : (height[j] + 1); //  height of histogram;
				int sum = 0;
				while (!s.empty() && height[s.top().first] >= height[j])
					s.pop();
				if (s.empty())
					sum = height[j] * (j + 1);
				else
					sum = height[j] * (j - s.top().first) + s.top().second;
				s.push({j, sum});
				res += sum;
			}
		}
		return res;
	}
};