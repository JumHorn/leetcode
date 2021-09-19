#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int finalValueAfterOperations(vector<string> &operations)
	{
		int res = 0;
		for (auto &s : operations)
			res += (s[1] == '+' ? 1 : -1);
		return res;
	}
};