#include <unordered_set>
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
	int numComponents(ListNode *head, vector<int> &G)
	{
		int res = 0;
		unordered_set<int> s(G.begin(), G.end());
		while (head != nullptr)
		{
			if (s.find(head->val) != s.end())
			{
				++res;
				while (head != nullptr && s.find(head->val) != s.end())
					head = head->next;
			}
			else
				head = head->next;
		}
		return res;
	}
};