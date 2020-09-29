#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfArithmeticSlices(vector<int> &A)
	{
		int count = 0, res = 0;
		for (int i = 2; i < (int)A.size(); i++)
		{
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
				++count;
			else
			{
				res += (count + 1) * count / 2;
				count = 0;
			}
		}
		return res + count * (count + 1) / 2;
	}
};