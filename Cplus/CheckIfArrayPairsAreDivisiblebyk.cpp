#include <vector>
using namespace std;

class Solution
{
public:
	bool canArrange(vector<int>& arr, int k)
	{
		vector<int> v(k);
		for (auto n : arr)
		{
			int index = n % k;
			if (index < 0)
				index += k;
			v[index] = 1 - v[index];
		}
		if (k % 2 == 1)
		{
			for (int i = 1; i <= k / 2; i++)
			{
				if ((v[i] + v[k - i]) % 2 != 0)
					return false;
			}
		}
		else
		{
			for (int i = 1; i < k / 2 - 1; i++)
			{
				if ((v[i] + v[k - i]) % 2 != 0)
					return false;
			}
			if (v[k / 2] % 2 != 0)
				return false;
		}
		return true;
	}
};
