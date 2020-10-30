#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> addToArrayForm(vector<int> &A, int K)
	{
		reverse(A.begin(), A.end());
		for (int carry = 0, i = 0; K != 0 || carry != 0; ++i, K /= 10)
		{
			if (i >= (int)A.size())
				A.push_back(0);
			carry += A[i] + K % 10;
			A[i] = carry % 10;
			carry /= 10;
		}
		reverse(A.begin(), A.end());
		return A;
	}
};