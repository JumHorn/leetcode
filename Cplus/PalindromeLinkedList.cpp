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
    ListNode* middle;
    bool isPalindrome(ListNode* head) {
        //找中间点
        ListNode *worker,*runner;
        worker=runner=middle=head;
        if(head==NULL||head->next==NULL)
        {
            return true;
        }
        while(runner!=NULL&&runner->next!=NULL)
        {
            middle=worker;
            worker=worker->next;
            runner = runner->next->next;
        }
        if(runner!=NULL)
        {
            worker = worker->next;
        }

        //实现逆序
        reverse(head);

        while(worker!=NULL)
        {
            if(worker->val != middle->val)
            {
                return false;
            }
            worker=worker->next;
            middle=middle->next;
        }
        return true;
        
    }
    ListNode* reverse(ListNode *p)
    {
        if(p!=middle)
        {
            ListNode* temp = reverse(p->next);
            temp->next = p;
        }
        p->next=NULL;
        return p;
    }
    
};