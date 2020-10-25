#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string toHex(int num)
	{
		unsigned int N = num;
		if (N == 0)
			return "0";
		string res;
		while (N != 0)
		{
			int n = (N & 0b1111); //N%16
			if (n < 10)
				res.push_back(n + '0');
			else
				res.push_back(n - 10 + 'a');
			N >>= 4; //N/=16
		}
		reverse(res.begin(), res.end());
		return res;
	}
};