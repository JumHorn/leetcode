#include <stack>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	vector<int> nextLargerNodes(ListNode* head)
	{
		vector<int> res;
		while (head != NULL)
		{
			res.push_back(head->val);
			head = head->next;
		}
		stack<int> s;
		for (int i = 0; i < (int)res.size(); i++)
		{
			if (s.empty())
				s.push(i);
			else
			{
				while (!s.empty() && res[i] > res[s.top()])
				{
					res[s.top()] = res[i];
					s.pop();
				}
				s.push(i);
			}
		}
		while (!s.empty())
		{
			res[s.top()] = 0;
			s.pop();
		}
		return res;
	}
};
