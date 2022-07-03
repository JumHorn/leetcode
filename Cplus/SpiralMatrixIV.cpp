#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
	{
		vector<vector<int>> res(m, vector<int>(n, -1));
		for (int i = 0, j = 0; i < m && j < n && head != nullptr;)
		{
			//right
			for (int k = j; k < n && head != nullptr; ++k)
			{
				res[i][k] = head->val;
				head = head->next;
			}
			++i;
			//down
			for (int k = i; k < m && head != nullptr; ++k)
			{
				res[k][n - 1] = head->val;
				head = head->next;
			}
			--n;
			//left
			for (int k = n - 1; k >= j && head != nullptr; --k)
			{
				res[m - 1][k] = head->val;
				head = head->next;
			}
			--m;
			//up
			for (int k = m - 1; k >= i && head != nullptr; --k)
			{
				res[k][j] = head->val;
				head = head->next;
			}
			++j;
		}
		return res;
	}
};