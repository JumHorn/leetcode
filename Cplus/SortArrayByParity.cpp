#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sortArrayByParity(vector<int> &A)
	{
		int i = 0, j = (int)A.size() - 1;
		while (i < j)
		{
			if ((A[i] & 1) == 0)
				++i;
			else if ((A[j] & 1) == 1)
				--j;
			else
				swap(A[i++], A[j--]);
		}
		return A;
	}
};