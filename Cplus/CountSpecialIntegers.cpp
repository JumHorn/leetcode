#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int countSpecialNumbers(int n)
	{
		vector<int> special = {0, 9, 81, 648, 4536, 27216, 136080, 544320, 1632960, 3265920, 3265920};
		string val = to_string(n);
		int N = val.size(), res = 0;
		for (int i = 0; i < N; ++i)
			res += special[i];
		res += (val[0] - '0' - 1) * P(9, N - 1);
		vector<int> seen(10);
		seen[val[0] - '0'] = 1;
		int i = 1;
		for (i = 1; i < N; ++i)
		{
			int k = 0;
			for (int j = 0; j < val[i] - '0'; ++j)
			{
				if (seen[j] == 0)
					++k;
			}
			res += k * P(9 - i, N - i - 1);
			if (seen[val[i] - '0'] == 1)
				break;
			seen[val[i] - '0'] = 1;
		}
		if (i == N)
			++res;
		return res;
	}

	int P(int n, int m) //permutation
	{
		int res = 1;
		for (int i = n; i > n - m; --i)
			res *= i;
		return res;
	}
};