#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> rearrangeArray(vector<int> &nums)
	{
		vector<int> negative, positive;
		for (auto n : nums)
		{
			if (n < 0)
				negative.push_back(n);
			else
				positive.push_back(n);
		}
		int N = positive.size();
		vector<int> res;
		for (int i = 0; i < N; ++i)
		{
			res.push_back(positive[i]);
			res.push_back(negative[i]);
		}
		return res;
	}
};