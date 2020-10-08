#include <string>
using namespace std;

class Solution
{
public:
	int monotoneIncreasingDigits(int N)
	{
		string digits = to_string(N);
		int i = 1, size = digits.size();
		while (i < size && digits[i] >= digits[i - 1])
			++i;
		if (i == size)
			return N;
		int j = i - 2;
		while (j >= 0 && digits[j] == digits[i - 1])
			--j;
		++j;
		digits[j] -= 1;
		while (++j < size)
			digits[j] = '9';
		return stoi(digits);
	}
};