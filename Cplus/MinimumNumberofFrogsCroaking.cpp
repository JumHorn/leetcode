#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minNumberOfFrogs(string croakOfFrogs)
	{
		unordered_map<char, int> index = //{char,index}
			{{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
		vector<int> state(5);
		int frog = 0, res = 0;
		for (auto c : croakOfFrogs)
		{
			if (c != 'c' && --state[index[c] - 1] < 0)
				return -1;
			++state[index[c]];
			if (c == 'c')
				++frog;
			else if (c == 'k')
				--frog;
			res = max(res, frog);
		}
		return frog == 0 ? res : -1;
	}
};