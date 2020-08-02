#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int countGoodTriplets(vector<int>& arr, int a, int b, int c)
	{
		int N = arr.size(), res = 0;
		for (int i = 0; i < N - 2; ++i)
		{
			for (int j = i + 1; j < N - 1; ++j)
			{
				if (abs(arr[i] - arr[j]) > a)
					continue;
				for (int k = j + 1; k < N; ++k)
				{
					if (abs(arr[j] - arr[k]) <= b && abs(arr[k] - arr[i]) <= c)
						++res;
				}
			}
		}
		return res;
	}
};
