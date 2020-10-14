#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	vector<TreeNode *> allPossibleFBT(int N)
	{
		if (N % 2 == 0)
			return {};
		vector<vector<TreeNode *>> dp(N + 1);
		dp[1].push_back(new TreeNode());
		for (int i = 3; i <= N; i += 2)
		{
			for (int j = 1; j < i; j += 2)
			{
				for (auto left : dp[j])
				{
					for (auto right : dp[i - 1 - j])
						dp[i].push_back(new TreeNode(0, left, right));
				}
			}
		}
		return dp[N];
	}
};