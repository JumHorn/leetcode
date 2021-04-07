#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string largestMultipleOfThree(vector<int> &digits)
	{
		count = vector<int>(10);
		sum = 0;
		string res;
		for (auto n : digits)
		{
			++count[n];
			sum += n;
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
			while (--count[i] >= 0)
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
		if (count[index] > 0)
		{
			--count[index];
			sum -= index % 3;
		}
		return sum % 3 == 0;
	}

private:
	int sum;
	vector<int> count;
};