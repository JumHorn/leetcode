#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string maximumOddBinaryNumber(string s)
	{
		int ones = count(s.begin(), s.end(), '1'), N = s.size();
		if (ones == 0)
			return s;
		if (ones == 1)
			return string(N - 1, '0') + '1';
		return string(ones - 1, '1') + string(N - ones, '0') + '1';
	}
};