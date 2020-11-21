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
		int N = A.size(), res = 1;
		vector<int> odd(N), even(N);
		odd[N - 1] = even[N - 1] = 1;
		map<int, int> m;
		m[A[N - 1]] = N - 1;
		for (int i = N - 2; i >= 0; --i)
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