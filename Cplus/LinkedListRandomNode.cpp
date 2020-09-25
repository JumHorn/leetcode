#include <cmath>
using namespace std;

/*
Algorithm:
Reservoir Sampling
*/

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
	/** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode *head) : head(head)
	{
	}

	/** Returns a random node's value. */
	int getRandom()
	{
		int res = head->val, n = 2;
		for (ListNode *p = head->next; p; p = p->next)
		{
			if (rand() % n++ == 0)
				res = p->val;
		}
		return res;
	}

private:
	ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */