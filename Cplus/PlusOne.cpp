#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int> &digits)
	{
		int carry = 1;
		for (int i = digits.size() - 1; i >= 0; --i)
		{
			carry += digits[i];
			digits[i] = carry % 10;
			carry /= 10;
		}
		if (carry == 0)
			return digits;
		digits.insert(digits.begin(), 1);
		return digits;
	}
};