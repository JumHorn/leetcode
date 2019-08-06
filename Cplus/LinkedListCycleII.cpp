#include<unordered_set>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
 		unordered_set<ListNode*> m;
		unordered_set<ListNode*>::iterator iter;
 		while(head!=NULL)
		{
			iter=m.find(head);
			if(iter!=m.end())
				return *iter;
			m.insert(head);
			head=head->next;
		}
		return NULL;
    }
};