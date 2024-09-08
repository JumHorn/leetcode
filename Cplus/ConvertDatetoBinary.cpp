#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string convertDateToBinary(string date)
	{
		string res;
		int y = 0, m = 0, d = 0;
		y = (date[0] - '0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
		m = (date[5] - '0') * 10 + (date[6] - '0');
		d = (date[8] - '0') * 10 + (date[9] - '0');
		return intToBinary(y) + "-" + intToBinary(m) + "-" + intToBinary(d);
	}

	string intToBinary(int x)
	{
		string res;
		for (; x > 0; x >>= 1)
			res.push_back('0' + (x & 1));
		reverse(res.begin(), res.end());
		return res;
	}
};