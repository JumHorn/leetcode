#include <algorithm>
using namespace std;

// Definition for a Node.
class Node
{
public:
	int val;
	Node *left;
	Node *right;
	Node *next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node *_left, Node *_right, Node *_next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
	Node *connect(Node *root)
	{
		Node dummy, *p = root, *d = &dummy;
		while (p)
		{
			if (p->left)
			{
				d->next = p->left;
				d = d->next;
			}
			if (p->right)
			{
				d->next = p->right;
				d = d->next;
			}
			p = p->next;
			if (!p) //next level
			{
				p = dummy.next;
				d = &dummy;
				d->next = NULL;
			}
		}
		return root;
	}
};