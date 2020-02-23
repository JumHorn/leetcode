#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string largestMultipleOfThree(vector<int> &digits)
	{
		string res;
		vector<vector<int>> v(3);
		int n = digits.size();
		for (int i = 0; i < n; i++)
		{
			if (digits[i] % 3 == 0)
				res.push_back(digits[i] + '0');
			else if (digits[i] % 3 == 1)
				v[1].push_back(digits[i]);
			else
				v[2].push_back(digits[i]);
		}
		sort(v[1].begin(), v[1].end(), greater<int>());
		sort(v[2].begin(), v[2].end(), greater<int>());
		n = min(v[1].size(), v[2].size());
		if (v[1].size() - n == 2 || v[2].size() - n == 2)
			if (n != 0)
				n = n - 1;
		for (int i = 0; i < n; i++)
		{
			res.push_back(v[1][i] + '0');
			res.push_back(v[2][i] + '0');
		}
		for (int i = n; i + 3 <= (int)v[1].size(); i += 3)
		{
			res.push_back(v[1][i] + '0');
			res.push_back(v[1][i + 1] + '0');
			res.push_back(v[1][i + 2] + '0');
		}
		for (int i = n; i + 3 <= (int)v[2].size(); i += 3)
		{
			res.push_back(v[2][i] + '0');
			res.push_back(v[2][i + 1] + '0');
			res.push_back(v[2][i + 2] + '0');
		}
		sort(res.begin(), res.end(), greater<char>());
		if (res.empty())
			return "";
		if (res.front() == '0')
			return "0";
		return res;
	}
};
