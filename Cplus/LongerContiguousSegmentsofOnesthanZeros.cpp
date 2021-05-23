#include <string>
using namespace std;

class Solution
{
public:
	bool checkZeroOnes(string s)
	{
		int one = 0, zero = 0, o = 0, z = 0;
		for (auto c : s)
		{
			if (c == '0')
			{
				++z;
				o = 0;
			}
			else
			{
				++o;
				z = 0;
			}
			one = max(one, o);
			zero = max(zero, z);
		}
		return one > zero;
	}
};