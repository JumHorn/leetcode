
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
	bool isPalindrome(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return true;
		//find middle
		ListNode *walker = head, *runner = head->next;
		while (runner != nullptr && runner->next != nullptr)
		{
			walker = walker->next;
			runner = runner->next->next;
		}
		runner = reverse(walker->next);
		walker = head;
		while (runner != nullptr)
		{
			if (walker->val != runner->val)
				return false;
			walker = walker->next;
			runner = runner->next;
		}
		return true;
	}

	ListNode *reverse(ListNode *head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode *res = reverse(head->next);
		head->next->next = head;
		head->next = nullptr;
		return res;
	}
};