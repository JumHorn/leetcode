#include <vector>
using namespace std;

class Solution
{
public:
	int reinitializePermutation(int n)
	{
		int res = 0;
		vector<int> arr(n), perm(n);
		for (int i = 0; i < n; ++i)
			arr[i] = perm[i] = i;
		do
		{
			++res;
			arr.swap(perm);
			for (int i = 0; i < n; ++i)
			{
				if (i % 2 == 0) //even
					arr[i] = perm[i / 2];
				else
					arr[i] = perm[n / 2 + (i - 1) / 2];
			}
		} while (!check(arr));
		return res;
	}

	bool check(vector<int> &v)
	{
		for (int i = 0; i < (int)v.size(); ++i)
		{
			if (v[i] != i)
				return false;
		}
		return true;
	}
};