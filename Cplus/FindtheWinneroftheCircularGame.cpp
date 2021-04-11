#include <vector>
using namespace std;

class Solution
{
public:
	int findTheWinner(int n, int k)
	{
		vector<int> v(n);
		for (int index = -1, i = 0; i < n - 1; ++i)
		{
			for (int i = 0; i < k;)
			{
				index = (index + 1) % n;
				if (v[index] == 0)
					++i;
			}
			v[index] = 1;
		}
		for (int i = 0; i < n; ++i)
		{
			if (v[i] == 0)
				return i + 1;
		}
		return 0;
	}
};