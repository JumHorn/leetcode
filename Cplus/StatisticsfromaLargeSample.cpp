#include <algorithm>
#include <vector>
using namespace std;

/*
最小值、最大值、平均值、中位数、众数
minimum, maximum, mean, median, mode
*/

class Solution
{
public:
	vector<double> sampleStats(vector<int> &count)
	{
		double minimum = 256, maximum = -1, mean = 0, median = 0, mode = 0;
		int N = count.size(), size = 0;
		long sum = 0;
		for (int i = 0; i < N; ++i)
		{
			if (count[i] == 0)
				continue;
			//maximum minimum
			if (i > maximum)
				maximum = i;
			//minimum
			if (i < minimum)
				minimum = i;
			//sum
			sum += count[i] * i;
			//size
			size += count[i];
			//mode
			if (count[i] > count[mode])
				mode = i;
		}
		//mean
		mean = sum * 1.0 / size;

		int prefixsum = 0, i = 0;
		for (i = 0; i < N && prefixsum * 2 < size; ++i)
			prefixsum += count[i];
		median = i - 1;
		if (size % 2 == 0 && prefixsum * 2 == size)
		{
			while (count[i] == 0)
				++i;
			median += i;
			median /= 2.0;
		}
		return {minimum, maximum, mean, median, mode};
	}
};