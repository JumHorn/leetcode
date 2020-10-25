#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
	{
		int N = l.size();
		vector<bool> res;
		vector<int> data(nums.size());
		for (int i = 0; i < N; ++i)
		{
			//vector<int> data=vector<int>(nums.begin()+l[i],nums.begin()+r[i]+1);
			int size = r[i] - l[i] + 1;
			if (size < 3)
				res.push_back(true);
			else
			{
				std::copy_n(nums.begin() + l[i], size, data.begin());
				res.push_back(checkArithmetic(data, size));
			}
		}
		return res;
	}

	bool checkArithmetic(vector<int> &data, int size)
	{
		sort(data.begin(), data.begin() + size);
		for (int i = 2; i < size; ++i)
		{
			if (data[i] - data[i - 1] != data[1] - data[0])
			{
				return false;
			}
		}
		return true;
	}
};