
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

struct ListNode* divide(struct ListNode** lists, int begin, int end)
{
	if (end == begin)
		return 0;
	if (end - begin == 1)
		return lists[begin];
	int mi = (end - begin) / 2 + begin;
	struct ListNode* left = divide(lists, begin, mi);
	struct ListNode* right = divide(lists, mi, end);
	return mergeTwoLists(left, right);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
	return divide(lists, 0, listsSize);
}
