#include <string>
using namespace std;

class Solution
{
public:
	bool makeStringsEqual(string s, string target)
	{
		int one1 = 0, one2 = 0;
		for (auto c : s)
		{
			if (c == '1')
				++one1;
		}
		for (auto c : target)
		{
			if (c == '1')
				++one2;
		}
		if (one2 == 0)
			return one1 == 0;
		if (one1 == 0)
			return one2 == 0;
		return true;
	}
};