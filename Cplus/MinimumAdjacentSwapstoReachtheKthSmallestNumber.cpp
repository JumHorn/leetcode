#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	int getMinSwaps(string num, int k)
	{
		string target = num;
		for (int i = 0; i < k; ++i)
			next_permutation(target.begin(), target.end());
		int res = 0, N = num.size();
		for (int i = 0; i < N; ++i)
		{
			if (num[i] != target[i])
			{
				int j = i + 1;
				while (num[j] != target[i])
					++j;
				res += j - i;
				for (; j > i; --j)
					swap(num[j], num[j - 1]);
			}
		}
		return res;
	}
};