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
    ListNode* middleNode(ListNode* head) {
        ListNode *walker,*runner;
	    walker=runner=head;
		while(runner!=NULL)
		{
			runner=runner->next;
			if(runner!=NULL)
			{
				walker=walker->next;
				runner=runner->next;
			}
		}	
		return walker;
    }
};
