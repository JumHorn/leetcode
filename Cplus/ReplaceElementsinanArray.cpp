#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
	{
		unordered_map<int, int> m;
		int N = nums.size();
		for (int i = 0; i < N; ++i)
			m[nums[i]] = i;
		for (auto &op : operations)
		{
			int a = op[0], b = op[1];
			int index = m[a];
			nums[index] = b;
			m.erase(a);
			m[b] = index;
		}
		return nums;
	}
};