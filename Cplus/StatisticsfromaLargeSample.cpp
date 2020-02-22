#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<double> sampleStats(vector<int>& count)
	{
		double minimum = 256, maximum = -1, mean = 0, median = 0, mode = 0;
		unsigned int n = count.size(), num = 0, modecount = 0;
		long sum = 0;
		for (unsigned int i = 0; i < n; i++)
		{
			//maximum minimum
			if (count[i] != 0)
			{
				if (i > maximum)
					maximum = i;
				if (i < minimum)
					minimum = i;
			}
			//mean
			sum += count[i] * i;
			num += count[i];
			//mode
			if (count[i] > (int)modecount)
			{
				modecount = count[i];
				mode = i;
			}
		}
		mean = sum * 1.0 / num;

		unsigned int sumprefix = 0;
		for (unsigned int i = 0; i < n; i++)
		{
			sumprefix += count[i];
			if (sumprefix * 2 >= num)
			{
				median = i;
				if (num % 2 == 0 && sumprefix * 2 == num)
				{
					while (++i < n && count[i] == 0)
						;
					median += i;
					median /= 2.0;
				}
				break;
			}
		}
		return {minimum, maximum, mean, median, mode};
	}
};

