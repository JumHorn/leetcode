#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> prevPermOpt1(vector<int> &A)
	{
		for (int i = A.size() - 1; i > 0; --i)
		{
			if (A[i] < A[i - 1])
			{
				int j = i + 1;
				while (j < (int)A.size() && A[j] < A[i - 1] && A[j] > A[i])
					j++;
				swap(A[i - 1], A[j - 1]);
				break;
			}
		}
		return A;
	}
};