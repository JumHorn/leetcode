#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr)
	{
		vector<vector<int>> res;
		sort(arr.begin(), arr.end());
		int diff = INT_MAX;
		for (int i = 1; i < (int)arr.size(); i++)
			diff = min(diff, arr[i] - arr[i - 1]);
		for (int i = 1; i < (int)arr.size(); i++)
			if (diff == arr[i] - arr[i - 1])
				res.push_back({arr[i - 1], arr[i]});
		return res;
	}
};
