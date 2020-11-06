#include <queue>
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
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		ListNode dummy, *d = &dummy;
		priority_queue<pair<int, ListNode *>> q;
		for (auto node : lists)
		{
			if (node != nullptr)
				q.push({-node->val, node});
		}
		while (!q.empty())
		{
			d->next = q.top().second;
			d = d->next;
			q.pop();
			if (d->next != nullptr)
				q.push({-d->next->val, d->next});
		}
		return dummy.next;
	}
};