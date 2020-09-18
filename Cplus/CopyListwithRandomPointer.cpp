#include <unordered_map>
#include <vector>
using namespace std;

// Definition for a Node.
class Node
{
public:
	int val;
	Node *next;
	Node *random;

	Node(int _val)
	{
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution
{
public:
	Node *copyRandomList(Node *head)
	{
		if (head == nullptr)
			return nullptr;
		unordered_map<Node *, Node *> m; //{src node,dst node}
		Node *res = new Node(head->val);
		m[head] = res;
		for (Node *p = head->next, *q = res; p; p = p->next, q = q->next)
		{
			m[p] = new Node(p->val);
			q->next = m[p];
		}
		for (Node *p = head, *q = res; p; p = p->next, q = q->next)
		{
			if (p->random)
				q->random = m[p->random];
		}
		return res;
	}
};