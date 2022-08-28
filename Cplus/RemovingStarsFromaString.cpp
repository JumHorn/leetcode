#include <string>
using namespace std;

class Solution
{
public:
	string removeStars(string s)
	{
		string res;
		for (auto c : s)
		{
			if (c == '*')
			{
				if (!res.empty())
					res.pop_back();
			}
			else
				res.push_back(c);
		}
		return res;
	}
};