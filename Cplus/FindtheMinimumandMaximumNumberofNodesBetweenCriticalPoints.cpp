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
	vector<int> nodesBetweenCriticalPoints(ListNode *head)
	{
		int index = 1, pre_ma = -1, first = -1, mind = INT_MAX, maxd = INT_MIN, pre = head->val;
		for (auto p = head->next; p != nullptr; p = p->next, ++index)
		{
			if (p->next != nullptr)
			{
				int after = p->next->val, cur = p->val;
				if ((cur > pre && cur > after) || (cur < pre && cur < after))
				{
					if (first == -1)
						first = index;
					if (pre_ma != -1)
					{
						mind = min(mind, index - pre_ma);
						maxd = index - first;
					}
					pre_ma = index;
				}
				pre = cur;
			}
		}
		if (mind == INT_MAX)
			return {-1, -1};
		return {mind, maxd};
	}
};