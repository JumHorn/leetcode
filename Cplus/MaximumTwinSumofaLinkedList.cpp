#include <algorithm>
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
	int pairSum(ListNode *head)
	{
		int res = 0;
		recursion(head, head, res);
		return res;
	}

	void recursion(ListNode *&head, ListNode *tail, int &res)
	{
		if (tail == nullptr)
			return;
		recursion(head, tail->next, res);
		res = max(res, head->val + tail->val);
		head = head->next;
	}
};