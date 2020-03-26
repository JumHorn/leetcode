
//Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list0, struct ListNode* list1)
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
	if (listsSize == 0)
		return 0;
	for (int i = 1; i < listsSize; i++)
		lists[0] = mergeTwoLists(lists[0], lists[i]);
	return lists[0];
}
