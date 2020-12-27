#include <string>
using namespace std;

class Solution
{
public:
	string maximumBinaryString(string binary)
	{
		int N = binary.size(), zero = 0, one = 0;
		for (auto c : binary)
		{
			if (c == '0')
				break;
			++one;
		}
		for (auto &c : binary)
		{
			if (c == '0')
				++zero;
			c = '1';
		}
		if (zero > 0)
			binary[zero - 1 + one] = '0';
		return binary;
	}
};