#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumDifference(vector<int> &nums)
	{
		int N = nums.size(), M = N / 3;
		vector<long long> left(N), right(N);

		priority_queue<int> q1;
		//left n
		long long sum = 0;
		for (int i = 0; i < M; ++i)
		{
			q1.push(nums[i]);
			sum += nums[i];
		}
		left[M - 1] = sum;
		for (int i = M; i < 2 * M; ++i)
		{
			int maxval = q1.top();
			if (maxval > nums[i])
			{
				q1.pop();
				sum -= maxval;
				sum += nums[i];
				q1.push(nums[i]);
			}
			left[i] = sum;
		}

		// right n
		priority_queue<int, vector<int>, greater<int>> q2;
		sum = 0;
		for (int i = N - 1; i >= N - M; --i)
		{
			q2.push(nums[i]);
			sum += nums[i];
		}
		right[N - M] = sum;
		for (int i = N - M - 1; i >= M; --i)
		{
			int minval = q2.top();
			if (minval < nums[i])
			{
				q2.pop();
				sum -= minval;
				sum += nums[i];
				q2.push(nums[i]);
			}
			right[i] = sum;
		}

		long long res = left[M - 1] - right[M];
		for (int i = M; i < 2 * M; ++i)
			res = min(res, left[i] - right[i + 1]);
		return res;
	}
};