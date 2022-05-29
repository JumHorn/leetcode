#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool digitCount(string num)
	{
		vector<int> count(10);
		for (auto c : num)
			++count[c - '0'];
		for (int i = 0; i < (int)num.size(); ++i)
		{
			if (count[i] != num[i] - '0')
				return false;
		}
		return true;
	}
};