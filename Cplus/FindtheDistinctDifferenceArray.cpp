#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> distinctDifferenceArray(vector<int> &nums)
	{
		int N = nums.size();
		vector<int> pre(N), suff(N);
		unordered_set<int> s, p;
		for (int i = 0; i < N; ++i)
		{
			p.insert(nums[i]);
			pre[i] = p.size();

			suff[N - i - 1] = s.size();
			s.insert(nums[N - i - 1]);
		}

		vector<int> res;
		for (int i = 0; i < N; ++i)
			res.push_back(pre[i] - suff[i]);
		return res;
	}
};