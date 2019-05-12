#include<vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
 		vector<ListNode*> v;
 		while(head!=NULL)
		{
			v.push_back(head);
			head=head->next;
		}		
		int s=v.size();
		if(n==1)
		{
			if(s==1)
				return NULL;
			v[s-2]->next=NULL;
			return v.front();
		}
		if(n==s)
		{
			return v[1];
		}
		v[s-n-1]->next=v[s-n+1];
		return v.front();
    }
};
