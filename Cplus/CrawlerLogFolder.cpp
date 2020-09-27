#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<string> &logs)
	{
		int res = 0;
		for (auto &log : logs)
		{
			if (log == "./")
			{
			}
			else if (log == "../")
			{
				if (res > 0)
					--res;
			}
			else
				++res;
		}
		return res;
	}
};