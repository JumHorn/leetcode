#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int countBalls(int lowLimit, int highLimit)
	{
		vector<int> count(50);
		for (int i = lowLimit; i <= highLimit; ++i)
		{
			int sum = 0;
			for (int n = i; n != 0; n /= 10)
				sum += n % 10;
			++count[sum];
		}
		return *max_element(count.begin(), count.end());
	}
};