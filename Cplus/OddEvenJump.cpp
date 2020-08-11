#include <algorithm>
#include <map>
#include <vector>
using namespace std;

/*
题目意思是先oddjump再evenjump一直循环看是否能到达终点
*/

class Solution
{
public:
	int oddEvenJumps(vector<int> &A)
	{
		int n = A.size(), res = 1;
		vector<int> odd(n), even(n);
		odd[n - 1] = even[n - 1] = 1;
		map<int, int> m;
		m[A[n - 1]] = n - 1;
		for (int i = n - 2; i >= 0; --i)
		{
			auto hi = m.lower_bound(A[i]), lo = m.upper_bound(A[i]);
			if (hi != m.end())
				odd[i] = even[hi->second];
			if (lo != m.begin())
				even[i] = odd[(--lo)->second];
			if (odd[i])
				++res;
			m[A[i]] = i;
		}
		return res;
	}
};