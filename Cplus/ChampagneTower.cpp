#include <vector>
using namespace std;

class Solution
{
public:
	double champagneTower(int poured, int query_row, int query_glass)
	{
		vector<double> res(query_row + 1);
		res[0] = poured;
		for (int i = 0; i < query_row; ++i)
		{
			for (int j = i; j >= 0; --j)
			{
				if (res[j] > 1)
				{
					res[j] -= 1;
					res[j + 1] += res[j] / 2.0;
					res[j] /= 2.0;
				}
				else
					res[j] = 0;
			}
		}
		return res[query_glass] > 1 ? 1 : res[query_glass];
	}
};