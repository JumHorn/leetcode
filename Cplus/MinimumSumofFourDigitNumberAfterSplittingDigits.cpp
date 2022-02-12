#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumSum(int num)
	{
		vector<int> v;
		for (; num > 0; num /= 10)
			v.push_back(num % 10);
		sort(v.begin(), v.end());
		return (v[0] + v[1]) * 10 + v[2] + v[3];
	}
};