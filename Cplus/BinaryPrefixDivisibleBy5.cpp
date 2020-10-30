#include <vector>
using namespace std;

class Solution
{
public:
	vector<bool> prefixesDivBy5(vector<int> &A)
	{
		vector<bool> res;
		int remainder = 0;
		for (auto n : A)
		{
			remainder = ((remainder << 1) | n) % 5;
			res.push_back(remainder == 0);
		}
		return res;
	}
};