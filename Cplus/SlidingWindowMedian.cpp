#include <queue>
#include <unordered_map>
using namespace std;

/*
lazy deletion
先标记，后删除

先从small加入，先从small删除，顺序不能错
*/

class Solution
{
public:
	vector<double> medianSlidingWindow(vector<int> &nums, int k)
	{
		// init
		priority_queue<int> small;
		priority_queue<int, vector<int>, greater<int>> big;
		unordered_map<int, int> delayed; //{val,count}
		for (int i = 0; i < k; ++i)
			small.push(nums[i]);
		for (int i = 0; i < k / 2; ++i)
		{
			big.push(small.top());
			small.pop();
		}

		// cal median
		auto getMedian = [&](int k)
		{
			return k % 2 == 0 ? ((double)small.top() + big.top()) / 2.0 : (double)small.top();
		};

		vector<double> res = {getMedian(k)};
		int N = nums.size();
		for (int i = k; i < N; ++i)
		{
			int balance = 0, num_remove = nums[i - k], num_add = nums[i];
			++delayed[num_remove];
			if (!small.empty() && num_remove <= small.top())
				++balance;
			else
				--balance;
			if (!small.empty() && num_add <= small.top())
			{
				--balance;
				small.push(num_add);
			}
			else
			{
				++balance;
				big.push(num_add);
			}

			if (balance > 0)
			{
				small.push(big.top());
				big.pop();
			}

			if (balance < 0)
			{
				big.push(small.top());
				small.pop();
			}

			// lazy deletion (small must be processed before big)
			for (; !small.empty() && delayed[small.top()] > 0; small.pop())
				--delayed[small.top()];
			for (; !big.empty() && delayed[big.top()] > 0; big.pop())
				--delayed[big.top()];

			res.push_back(getMedian(k));
		}
		return res;
	}
};