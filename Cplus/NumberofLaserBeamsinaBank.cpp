#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfBeams(vector<string> &bank)
	{
		vector<int> count;
		for (auto &v : bank)
		{
			int n = 0;
			for (auto c : v)
			{
				if (c == '1')
					++n;
			}
			count.push_back(n);
		}
		int pre = 0, res = 0;
		for (auto n : count)
		{
			res += pre * n;
			if (n != 0)
				pre = n;
		}
		return res;
	}
};