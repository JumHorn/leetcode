#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string addSpaces(string s, vector<int> &spaces)
	{
		int count = 0, N = spaces.size(), index = 0;
		string res;
		for (auto c : s)
		{
			if (index < N && count == spaces[index])
			{
				++index;
				res.push_back(' ');
			}
			res.push_back(c);
			++count;
		}
		return res;
	}
};