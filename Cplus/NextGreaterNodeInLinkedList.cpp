#include <stack>
#include <vector>
using namespace std;

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
	vector<int> nextLargerNodes(ListNode *head)
	{
		vector<int> res;
		stack<pair<int, int>> s; //{value,index}
		for (int index = 0; head != nullptr; ++index)
		{
			res.push_back(0);
			while (!s.empty() && s.top().first < head->val)
			{
				res[s.top().second] = head->val;
				s.pop();
			}
			s.push({head->val, index});
			head = head->next;
		}
		return res;
	}
};