#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
	int minSumOfLengths(vector<int> &arr, int target)
	{
		map<int, int> m; //{len,count}
		int n = arr.size();
		int sum = arr[0];
		for (int i = 0, j = 1;;)
		{
			if (sum == target)
			{
				++m[j - i];
				i = j;
				sum = 0;
			}
			else if (sum > target)
				sum -= arr[i++];
			else
			{
				if (j >= n)
					break;
				while (j < n && sum < target)
					sum += arr[j++];
			}
		}
		int res = 0, count = 0;
		for (auto iter : m)
		{
			if (count >= 2)
				break;
			res += iter.first * min(iter.second, 2 - count);
			count += iter.second;
		}
		if (count < 2)
			return -1;
		return res;
	}
};