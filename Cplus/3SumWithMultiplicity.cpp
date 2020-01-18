#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int threeSumMulti(vector<int> &A, int target)
	{
		if ((int)A.size() < 3)
			return 0;
		vector<unordered_map<int, int>> dp(A.size());
		for (int i = 1; i < (int)A.size(); i++)
			for (int j = 0; j < i; j++)
			{
				int sum = A[i] + A[j];
				if (dp[i][sum] + 1 == MOD)
					dp[i][sum] = 0;
				else
					++dp[i][sum];
			}
		int res = 0;
		for (int i = 2; i < (int)A.size(); i++)
			for (int j = 1; j < i; j++)
				res = (res + dp[j][target - A[i]]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};

int main()
{
	vector<int> v = {1, 1, 2, 2, 2, 2};
	Solution sol;
	sol.threeSumMulti(v, 5);
	return 0;
}