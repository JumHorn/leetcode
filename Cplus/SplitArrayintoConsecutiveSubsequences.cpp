#include <vector>
using namespace std;

class Solution
{
public:
	bool isPossible(vector<int> &nums)
	{
		int a = 0, b = 0, c = 0, N = nums.size(); //a >= 3 b = 1 c = 2
		for (int i = 0, j = 0; i < N; i = j)
		{
			j = i + 1;
			while (j < N && nums[i] == nums[j])
				++j;
			if (i >= 1 && nums[i] != nums[i - 1] + 1)
			{
				if (b != 0 || c != 0)
					return false;
				a = b = c = 0;
			}
			int tmp = a, diff = j - i - b - c;
			if (diff < 0)
				return false;
			a = min(a, diff);
			a += c;
			c = b;
			if (diff > tmp)
				b = diff - tmp;
			else
				b = 0;
		}
		return b == 0 && c == 0;
	}
};