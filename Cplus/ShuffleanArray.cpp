#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution(vector<int> &nums) : origin(nums)
	{
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset()
	{
		return origin;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle()
	{
		vector<int> copy(origin);
		int n = copy.size();
		for (int i = 0; i < n; ++i)
		{
			int tmp = rand() % (n - i) + i;
			swap(copy[i], copy[tmp]);
		}
		return copy;
	}

private:
	vector<int> origin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
