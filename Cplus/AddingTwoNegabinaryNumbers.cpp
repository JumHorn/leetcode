#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> addNegabinary(vector<int> &arr1, vector<int> &arr2)
	{
		int i = arr1.size(), j = arr2.size();
		int carry0 = 0, carry1 = 0;
		vector<int> sum;
		while (i > 0 || j > 0 || carry0 > 0 || carry1 > 0)
		{
			int bit = 0;
			bit += (--i >= 0 ? arr1[i] : 0);
			bit += (--j >= 0 ? arr2[j] : 0);
			bit += carry0;
			if (carry1 < bit / 2)
				carry1 = carry0 = 1;
			else
			{
				carry0 = carry1 - bit / 2;
				carry1 = 0;
			}
			sum.push_back(bit % 2);
		}
		vector<int> res;
		int N = sum.size();
		i = N - 1;
		while (i >= 0 && sum[i] == 0)
			--i;
		while (i >= 0)
			res.push_back(sum[i--]);
		return res.empty() ? vector<int>(1, 0) : res;
	}
};