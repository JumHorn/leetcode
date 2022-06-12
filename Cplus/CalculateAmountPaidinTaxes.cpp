#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	double calculateTax(vector<vector<int>> &brackets, int income)
	{
		vector<double> tax = {0}; //accumulate
		int pre = 0;
		for (auto &b : brackets)
		{
			tax.push_back(tax.back() + (b[0] - pre) * b[1] / 100.0);
			pre = b[0];
		}
		if (income <= brackets[0][0])
			return income * brackets[0][1] / 100.0;
		int index = lower_bound(brackets.begin(), brackets.end(), vector<int>({income, 0})) - brackets.begin();
		return tax[index] + (income - brackets[index - 1][0]) * brackets[index][1] / 100.0;
	}
};