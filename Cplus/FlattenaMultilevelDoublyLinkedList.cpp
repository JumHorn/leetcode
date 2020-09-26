
// Definition for a Node.
class Node
{
public:
	int val;
	Node *prev;
	Node *next;
	Node *child;

	Node() {}

	Node(int _val, Node *_prev, Node *_next, Node *_child)
	{
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

class Solution
{
public:
	Node *flatten(Node *head)
	{
		if (head == nullptr)
			return head;
		Node *node = head;
		while (node != nullptr)
		{
			Node *tmp = node;
			node = node->next;
			flatten(tmp, node);
		}
		return head;
	}

	void flatten(Node *head, Node *tail)
	{
		if (head->child == nullptr)
			return;
		head->next = head->child;
		head->child->prev = head;
		Node *childhead, *childtail = head->child;
		head->child = nullptr;
		while (childtail != nullptr)
		{
			childhead = childtail;
			childtail = childtail->next;
			flatten(childhead, childtail);
		}
		while (childhead->next != nullptr)
			childhead = childhead->next;
		childhead->next = tail;
		if (tail != nullptr)
			tail->prev = childhead;
	}
};