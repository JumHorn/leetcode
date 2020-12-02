
//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list0, struct ListNode *list1)
{
	if (!list0)
		return list1;
	if (!list1)
		return list0;
	if (list0->val <= list1->val)
	{
		list0->next = mergeTwoLists(list0->next, list1);
		return list0;
	}
	list1->next = mergeTwoLists(list0, list1->next);
	return list1;
}

struct ListNode *divide(struct ListNode **lists, int first, int last)
{
	if (last == first)
		return 0;
	if (last - first == 1)
		return lists[first];
	int mid = (last - first) / 2 + first;
	struct ListNode *left = divide(lists, first, mid);
	struct ListNode *right = divide(lists, mid, last);
	return mergeTwoLists(left, right);
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
	return divide(lists, 0, listsSize);
}