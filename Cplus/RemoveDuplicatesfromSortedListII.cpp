
//Definition for singly-linked list.
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
	ListNode *deleteDuplicates(ListNode *head)
	{
		ListNode **indirect = &head;
		while ((*indirect) != nullptr && (*indirect)->next != nullptr)
		{
			if ((*indirect)->val == (*indirect)->next->val)
			{
				while ((*indirect) != nullptr && (*indirect)->next != nullptr && (*indirect)->val == (*indirect)->next->val)
					*indirect = (*indirect)->next;
				*indirect = (*indirect)->next;
			}
			else
				indirect = &((*indirect)->next);
		}
		return head;
	}
};