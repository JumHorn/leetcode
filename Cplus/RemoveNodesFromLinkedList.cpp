#include <climits>
#include <stack>
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
	ListNode *removeNodes(ListNode *head)
	{
		ListNode dummy(INT_MAX), *d = &dummy;
		stack<ListNode *> stk;
		stk.push(d);
		for (; head != nullptr; head = head->next)
		{
			while (!stk.empty() && head->val > stk.top()->val)
				stk.pop();
			stk.top()->next = head;
			stk.push(head);
		}
		return dummy.next;
	}
};