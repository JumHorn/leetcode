#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumBoxes(vector<int> &apple, vector<int> &capacity)
	{
		sort(capacity.begin(), capacity.end(), greater<int>());
		int sum = accumulate(apple.begin(), apple.end(), 0);
		int N = capacity.size();
		for (int i = 0; i < N; ++i)
		{
			sum -= capacity[i];
			if (sum <= 0)
				return i + 1;
		}
		return -1;
	}
};