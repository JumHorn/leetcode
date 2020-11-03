#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximalRectangle(vector<vector<char>> &matrix)
	{
		if (matrix.empty() || matrix[0].empty())
			return 0;
		vector<int> H(matrix[0].size());
		int res = 0;
		for (int i = 0; i < (int)matrix.size(); ++i)
		{
			for (int j = 0; j < (int)matrix[0].size(); j++)
				matrix[i][j] == '1' ? ++H[j] : (H[j] = 0);
			res = max(res, solveHistogram(H));
		}
		return res;
	}

	int solveHistogram(vector<int> &H)
	{
		stack<int> s;
		int i = 0, res = 0;
		while (i < (int)H.size())
		{
			while (!s.empty() && H[i] < H[s.top()])
			{
				int height = s.top();
				s.pop();
				int width = s.empty() ? i : (i - (s.top() + 1));
				res = max(res, H[height] * width);
			}
			s.push(i++);
		}
		while (!s.empty())
		{
			int height = s.top();
			s.pop();
			int width = s.empty() ? i : (i - (s.top() + 1));
			res = max(res, H[height] * width);
		}
		return res;
	}
};