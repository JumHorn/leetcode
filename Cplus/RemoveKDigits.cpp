#include <string>
using namespace std;

class Solution
{
public:
	string removeKdigits(string num, int k)
	{
		string res;
		for (auto c : num)
		{
			while (k > 0 && !res.empty() && res.back() > c)
			{
				res.pop_back();
				--k;
			}
			res.push_back(c);
		}
		while (--k >= 0)
			res.pop_back();
		//trim leading zero
		int i = 0;
		while (i < (int)res.length() && res[i] == '0')
			++i;
		return i < (int)res.length() ? res.substr(i) : "0";
	}
};