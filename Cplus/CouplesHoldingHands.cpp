#include <vector>
using namespace std;

class Solution
{
public:
	int minSwapsCouples(vector<int> &row)
	{
		int res = 0, N = row.size();
		for (int i = 0; i < N; i += 2)
		{
			int match = (row[i] & 1) ? row[i] - 1 : row[i] + 1;
			if (row[i + 1] != match)
			{
				++res;
				for (int j = i + 2; j < N; ++j)
				{
					if (match == row[j])
						row[j] = row[i + 1];
				}
			}
		}
		return res;
	}
};