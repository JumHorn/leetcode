#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int findBestValue(vector<int> &arr, int target)
	{
		sort(arr.begin(), arr.end());
		int sum = accumulate(arr.begin(), arr.end(), 0);
		int s = sum;
		if (sum <= target)
			return arr.back();
		for (int i = arr.size() - 1; i > 0; --i)
		{
			sum -= (arr[i] - arr[i - 1]) * (arr.size() - i);
			if (sum == target)
				return arr[i - 1];
			if (sum < target)
			{
				int tmp = (target - sum) / (arr.size() - i);
				if (target - (sum + tmp * (arr.size() - i)) <= (sum + (tmp + 1) * (arr.size() - 1)) - target)
					return arr[i - 1] + tmp;
				else
					return arr[i - 1] + tmp + 1;
			}
		}
		int tmp = target / arr.size();
		if (target - tmp * arr.size() <= ((tmp + 1) * arr.size() - target))
			return tmp;
		return tmp + 1;
	}
};

// int main()
// {
// 	Solution sol;
// 	vector<int> v = {60864, 25176, 27249, 21296, 20204};
// 	return sol.findBestValue(v, 56803);
// }