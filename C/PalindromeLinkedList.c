#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

bool checkPalindrome(struct ListNode **head, struct ListNode *tail)
{
	if (!tail)
		return true;
	bool res = checkPalindrome(head, tail->next);
	if (!res || (*head)->val != tail->val)
		return false;
	*head = (*head)->next;
	return res;
}

bool isPalindrome(struct ListNode *head)
{
	return checkPalindrome(&head, head);
}