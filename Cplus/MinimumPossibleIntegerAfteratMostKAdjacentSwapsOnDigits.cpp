#include <string>
using namespace std;

class Solution
{
public:
	string minInteger(string num, int k)
	{
		int n = num.length();
		if (k >= n * (n - 1) / 2)
		{
			sort(num.begin(), num.end());
			return num;
		}
		recursion(num, 0, k);
		return num;
	}

	void recursion(string &num, int index, int k)
	{
		int n = num.length();
		if (k == 0 || index >= n)
			return;
		auto iter = min_element(num.begin() + index, num.begin() + index + min(k + 1, n - index));
		for (int i = iter - num.begin(); i > index; --i)
		{
			swap(num[i], num[i - 1]);
		}
		recursion(num, index + 1, k - (iter - num.begin()) + index);
	}
};