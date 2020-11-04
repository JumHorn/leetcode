#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canArrange(vector<int> &arr, int k)
	{
		vector<int> v(k);
		for (auto n : arr)
		{
			int index = n % k;
			if (index < 0)
				index += k;
			++v[index];
		}
		for (int i = 1; i < k / 2 + 1; ++i)
		{
			if (v[i] != v[k - i])
				return false;
		}
		if (k % 2 == 0 && v[k / 2] % 2 != 0)
			return false;
		return true;
	}
};