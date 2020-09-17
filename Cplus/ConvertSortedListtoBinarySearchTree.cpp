#include <vector>
using namespace std;

/*
inorder generate tree with [1,n]
then fill list node in inorder traversal
*/

//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Definition for a binary tree node.
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
	TreeNode *sortedListToBST(ListNode *head)
	{
		int size = getSize(head);
		return inorder(head, 0, size);
	}

	TreeNode *inorder(ListNode *&head, int first, int last) //[first,last)
	{
		if (first >= last)
			return nullptr;
		int mi = (last - first) / 2 + first;
		TreeNode *root = new TreeNode();
		root->left = inorder(head, first, mi);
		root->val = head->val;
		head = head->next;
		root->right = inorder(head, mi + 1, last);
		return root;
	}

	int getSize(ListNode *head)
	{
		int res = 0;
		while (head)
		{
			++res;
			head = head->next;
		}
		return res;
	}
};