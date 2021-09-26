#include <algorithm>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int scoreOfStudents(string s, vector<int> &answers)
	{
		int N = s.length();
		int correct = calculate(s);
		vector<vector<unordered_set<int>>> dp(N, vector<unordered_set<int>>(N + 1));
		diffWaysToCompute(s, 0, N, dp);
		auto &accept = dp[0][N];
		vector<bool> v(1001);
		for (auto n : accept)
		{
			if (n <= 1000)
				v[n] = true;
		}
		int res = 0;
		for (auto n : answers)
		{
			if (n == correct)
				res += 5;
			else if (v[n])
				res += 2;
		}
		return res;
	}

	void diffWaysToCompute(string &input, int l, int r, vector<vector<unordered_set<int>>> &dp)
	{
		if (!dp[l][r].empty())
			return;
		unordered_set<int> res;
		for (int i = l; i < r; ++i)
		{
			if (input[i] == '+' || input[i] == '-' || input[i] == '*')
			{
				diffWaysToCompute(input, l, i, dp);
				diffWaysToCompute(input, i + 1, r, dp);
				auto &left = dp[l][i], &right = dp[i + 1][r];
				for (auto n : left)
				{
					for (auto m : right)
					{
						if (input[i] == '+')
						{
							if (n + m <= 1000)
								res.insert(n + m);
						}
						else if (input[i] == '-')
							res.insert(n - m);
						else
						{
							if (n * m <= 1000)
								res.insert(n * m);
						}
					}
				}
			}
		}
		if (res.empty())
			res.insert(input[l] - '0');
		dp[l][r] = res;
	}

	int calculate(string s)
	{
		stringstream ss(s);
		int res, pre, val;
		char op;
		ss >> res;
		pre = res;
		while (ss >> op)
		{
			ss >> val;
			if (op == '+')
				pre = val;
			else if (op == '-')
				pre = -val;
			else if (op == '*')
			{
				res -= pre;
				pre *= val;
			}
			else // '/'
			{
				res -= pre;
				pre /= val;
			}
			res += pre;
		}
		return res;
	}
};