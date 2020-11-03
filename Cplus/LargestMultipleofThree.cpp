#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string largestMultipleOfThree(vector<int> &digits)
	{
		v = vector<int>(10);
		sum = 0;
		string res;
		int n = digits.size();
		for (int i = 0; i < n; ++i)
		{
			++v[digits[i]];
			sum += digits[i];
		}

		if (sum % 3 == 1)
		{
			if (!(f(1) || f(4) || f(7)))
				f(2) || f(2) || f(5) || f(5) || f(8) || f(8);
		}
		else if (sum % 3 == 2)
		{
			if (!(f(2) || f(5) || f(8)))
				f(1) || f(1) || f(4) || f(4) || f(7) || f(7);
		}

		for (int i = 9; i >= 0; --i)
		{
			while (--v[i] >= 0)
				res.push_back(i + '0');
		}
		if (res.empty())
			return "";
		if (res[0] == '0')
			return "0";
		return res;
	}

	bool f(int index)
	{
		if (v[index] > 0)
		{
			--v[index];
			sum -= index % 3;
		}
		return sum % 3 == 0;
	}

private:
	int sum;
	vector<int> v;
};