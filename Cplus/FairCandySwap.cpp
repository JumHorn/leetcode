#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
	{
		unordered_set<int> m(B.begin(), B.end());
		int sumA = accumulate(A.begin(), A.end(), 0);
		int sumB = accumulate(B.begin(), B.end(), 0);
		int avg = (sumA + sumB) / 2;
		for (auto n : A)
		{
			if (m.find(avg + n - sumA) != m.end())
				return {n, avg + n - sumA};
		}
		return {};
	}
};