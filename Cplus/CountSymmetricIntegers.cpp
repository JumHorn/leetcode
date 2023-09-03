#include <string>
using namespace std;

class Solution
{
public:
	int countSymmetricIntegers(int low, int high)
	{
		int res = 0;
		for (int i = low; i <= high; ++i)
			res += isSymmetricIntegers(i);
		return res;
	}

	int isSymmetricIntegers(int n)
	{
		string num = to_string(n);
		if (num.size() % 2 == 1)
			return 0;
		int N = num.size(), pre = 0, suf = 0;
		for (int i = 0; i < N / 2; ++i)
		{
			pre += num[i] - '0';
			suf += num[N - 1 - i] - '0';
		}
		return pre == suf ? 1 : 0;
	}
};