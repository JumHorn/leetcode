#include <vector>
using namespace std;

class Solution
{
public:
	bool isIdealPermutation(vector<int> &A)
	{
		int premax = 0;
		for (int i = 0; i < (int)A.size() - 2; ++i)
		{
			premax = max(premax, A[i]);
			if (premax > A[i + 2])
				return false;
		}
		return true;
	}
};