#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> minOperations(string boxes)
	{
		int N = boxes.size(), sum = boxes.front() - '0';
		vector<int> prefix(N), suffix(N);
		for (int i = 1; i < N; ++i)
		{
			prefix[i] += prefix[i - 1] + sum;
			sum += boxes[i] - '0';
		}
		sum = boxes.back() - '0';
		for (int i = N - 2; i >= 0; --i)
		{
			suffix[i] += suffix[i + 1] + sum;
			sum += boxes[i] - '0';
		}
		vector<int> res;
		for (int i = 0; i < N; ++i)
			res.push_back(prefix[i] + suffix[i]);
		return res;
	}
};