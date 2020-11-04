#include <vector>
using namespace std;

class Solution
{
public:
	int kthFactor(int n, int k)
	{
		vector<int> factor;
		for (int i = 1; i * i <= n && (int)factor.size() < k; ++i)
		{
			if (n % i == 0)
				factor.push_back(i);
		}
		int N = factor.size();
		if (k <= N)
			return factor.back();
		bool square = (factor.back() * factor.back() == n);
		if (k > N * 2 - (square ? 1 : 0))
			return -1;
		return n / factor[N - (k - N)];
	}
};