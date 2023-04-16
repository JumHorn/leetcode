#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
	{
		int row = 0;
		vector<int> r;
		for (auto &v : mat)
		{
			int count = 0;
			for (auto n : v)
				count += n;
			r.push_back(count);
		}
		for (int i = 1; i < r.size(); ++i)
		{
			if (r[i] > r[row])
				row = i;
		}
		return {row, r[row]};
	}
};