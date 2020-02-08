#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int numOfSubarrays(vector<int>& arr, int k, int threshold)
	{
		threshold *= k;
		int sum = accumulate(arr.begin(), arr.begin() + k, 0);
		int res = 0;
		if (sum >= threshold)
			res++;
		for (int i = k; i < (int)arr.size(); i++)
		{
			sum = sum + arr[i] - arr[i - k];
			if (sum >= threshold)
				res++;
		}
		return res;
	}
};
