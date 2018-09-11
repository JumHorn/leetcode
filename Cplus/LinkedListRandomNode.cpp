#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
	int len;
	ListNode* head;
    Solution(ListNode* head) {
		this->head=head;
		len=1;
		ListNode* p=head;
        while(p->next!=NULL)
		{
			len++;
			p=p->next;
		}
		p->next=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
		int num=1 + std::rand()/((RAND_MAX + 1u)/len);
		for(int i=0;i<num;i++)
		{
			head=head->next;
		}
		return head->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
