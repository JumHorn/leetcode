#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sortByBits(vector<int> &arr)
	{
		sort(arr.begin(), arr.end(), *this);
		return arr;
	}

	bool operator()(int lhs, int rhs)
	{
		int a = bitset<32>(lhs).count(), b = bitset<32>(rhs).count();
		if (a != b)
			return a < b;
		return lhs < rhs;
	}
};