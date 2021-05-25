#include <vector>
using namespace std;

class Solution
{
public:
	bool reorderedPowerOf2(int N)
	{
		vector<int> count = countDigits(N);
		for (int i = 0; i < 32; ++i)
		{
			if (countDigits(1u << i) == count)
				return true;
		}
		return false;
	}

	vector<int> countDigits(unsigned int val)
	{
		vector<int> count(10);
		for (; val != 0; val /= 10)
			++count[val % 10];
		return count;
	}
};