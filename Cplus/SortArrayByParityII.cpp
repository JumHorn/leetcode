#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sortArrayByParityII(vector<int> &A)
	{
		int N = A.size();
		for (int odd = 1, even = 0; odd < N && even < N;)
		{
			if (A[odd] % 2 == 1)
				odd += 2;
			else if (A[even] % 2 == 0)
				even += 2;
			else
			{
				swap(A[odd], A[even]);
				odd += 2;
				even += 2;
			}
		}
		return A;
	}
};