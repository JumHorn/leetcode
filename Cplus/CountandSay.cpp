#include <string>
using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		if (n == 1)
			return "1";
		string data = countAndSay(n - 1), res;
		char pre = -1;
		int count = 0;
		for (auto c : data)
		{
			if (pre != c)
			{
				if (count != 0)
					res += to_string(count) + pre;
				pre = c;
				count = 1;
			}
			else
				++count;
		}
		res += to_string(count) + pre;
		return res;
	}
};