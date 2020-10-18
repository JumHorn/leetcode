#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	double trimMean(vector<int> &arr)
	{
		sort(arr.begin(), arr.end());
		int N = arr.size(), sum = 0;
		for (int i = N * 0.05; i < N - 0.05 * N; ++i)
			sum += arr[i];
		return sum * 1.0 / (N - 0.1 * N);
	}
};