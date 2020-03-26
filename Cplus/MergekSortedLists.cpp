#include <vector>
#include <queue>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		ListNode *dummy = new ListNode(0), *res = dummy;
		priority_queue<pair<int, ListNode *>> q;
		for (int i = 0; i < (int)lists.size(); i++)
			if (lists[i] != NULL)
				q.push({-lists[i]->val, lists[i]});
		while (!q.empty())
		{
			dummy->next = q.top().second;
			dummy = dummy->next;
			q.pop();
			if (dummy->next != NULL)
				q.push({-dummy->next->val, dummy->next});
		}
		return res->next;
	}
};