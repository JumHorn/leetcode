
// Definition for singly-linked list.
struct ListNode
{
	int val;
	struct ListNode* next;
};

int numComponents(struct ListNode* head, int* G, int GSize)
{
	int hash[10000] = {0};
	for (int i = 0; i < GSize; ++i)
		hash[G[i]] = 1;
	int res = 0;
	while (head)
	{
		if (hash[head->val] == 1 && (!head->next || hash[head->next->val] == 0))
			++res;
		head = head->next;
	}
	return res;
}
