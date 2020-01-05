#include <vector>
using namespace std;
//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *removeZeroSumSublists(ListNode *head)
	{
		vector<int> v;
		ListNode *tmp = head;
		while (tmp)
		{
			v.push_back(tmp->val);
			tmp = tmp->next;
		}
		for (int i = 0; i < (int)v.size(); i++)
		{
			if (v[i] == 0)
			{
				v[i] = INT_MAX;
				continue;
			}
			int j = i - 1;
			int sum = v[i];
			for (; j >= 0; j--)
			{
				if (v[j] != INT_MAX)
				{
					sum += v[j];
					if (sum == 0)
					{
						while (j <= i)
							v[j++] = INT_MAX;
						break;
					}
				}
			}
		}
		int index = 0;
		ListNode *dummzy = new ListNode(0);
		tmp = dummzy;
		while (head)
		{
			if (v[index] != INT_MAX)
			{
				tmp->next = head;
				tmp = tmp->next;
			}
			++index;
			head = head->next;
			tmp->next = NULL;
		}
		return dummzy->next;
	}
};