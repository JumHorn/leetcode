#include <vector>
using namespace std;

class Solution
{
public:
	int getXORSum(vector<int> &arr1, vector<int> &arr2)
	{
		vector<int> v1(30), v2(30);
		for (auto n : arr1)
		{
			for (int i = 0; i < 30; ++i)
			{
				if (n & (1 << i))
					++v1[i];
			}
		}
		for (auto n : arr2)
		{
			for (int i = 0; i < 30; ++i)
			{
				if (n & (1 << i))
					++v2[i];
			}
		}
		int res = 0;
		for (int i = 0; i < 30; ++i)
		{
			if ((long)v1[i] * v2[i] % 2)
				res |= (1 << i);
		}
		return res;
	}
};