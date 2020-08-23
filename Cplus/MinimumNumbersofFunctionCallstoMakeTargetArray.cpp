#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int>& nums)
	{
		int res = 0;
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (auto& n : nums)
			{
				if (n % 2 == 1)
					++res;
				n /= 2;
				if (n != 0)
					flag = true;
			}
			++res;
		}
		return res - 1;
	}
};
