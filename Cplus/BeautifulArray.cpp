#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> beautifulArray(int N)
	{
		vector<int> res(N);
		for (int i = 1; i <= N; i++)
			res[i - 1] = i;
		backTracking(res, 0);
		return res;
	}

	bool backTracking(vector<int>& res, int index)
	{
		int n = res.size();
		if (index == n)
			return true;
		for (int i = index; i < n; i++)
		{
			swap(res[i], res[index]);
			if (checkValid(res, index) && backTracking(res, index + 1))
				return true;
			swap(res[i], res[index]);
		}
		return false;
	}

	bool checkValid(vector<int>& res, int j)
	{
		for (int i = 0; i < j - 1; i++)
		{
			for (int k = i + 1; k < j; k++)
			{
				if (2 * res[k] == res[i] + res[j])
					return false;
			}
		}
		return true;
	}
};
