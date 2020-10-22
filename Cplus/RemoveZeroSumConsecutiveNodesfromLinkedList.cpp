#include <unordered_map>
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
	ListNode *removeZeroSumSublists(ListNode *head)
	{
		ListNode dummy;
		dummy.next = head;
		unordered_map<int, ListNode *> m; //{prefixsum,ListNode}
		int prefixsum = 0;
		for (ListNode *p = &dummy; p != nullptr; p = p->next)
		{
			prefixsum += p->val;
			m[prefixsum] = p;
		}
		prefixsum = 0;
		for (ListNode *p = &dummy; p != nullptr; p = p->next)
		{
			prefixsum += p->val;
			p->next = m[prefixsum]->next;
		}
		return dummy.next;
	}
};