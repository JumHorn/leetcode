#include <algorithm>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	bool isSubPath(ListNode* head, TreeNode* root)
	{
		return dfs(head, root);
	}

	bool checkPath(ListNode* head, TreeNode* root)
	{
		if (head == NULL)
			return true;
		if (root == NULL)
			return false;
		if (head->val != root->val)
			return false;
		return checkPath(head->next, root->left) || checkPath(head->next, root->right);
	}

	bool dfs(ListNode* head, TreeNode* root)
	{
		if (root == NULL)
			return false;
		if (checkPath(head, root))
			return true;
		return dfs(head, root->left) || dfs(head, root->right);
	}
};
