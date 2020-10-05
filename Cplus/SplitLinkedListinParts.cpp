#include <vector>
using namespace std;

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
	vector<ListNode *> splitListToParts(ListNode *root, int k)
	{
		int size = listSize(root);
		vector<ListNode *> res;
		int part = size / k;
		for (int i = 0; i < k; ++i)
		{
			res.push_back(root);
			for (int j = 0; j < part - (i >= size % k ? 1 : 0); ++j)
				root = root->next;
			if (root != nullptr)
			{
				ListNode *p = root;
				root = root->next;
				p->next = nullptr;
			}
		}
		return res;
	}

	int listSize(ListNode *head)
	{
		if (head == nullptr)
			return 0;
		return listSize(head->next) + 1;
	}
};