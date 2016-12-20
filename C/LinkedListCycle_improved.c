#include<stdio.h>
//definition for singly-linked lsit
struct ListNode
{
    int val;
    struct ListNode *next;
};
int main()
{
    bool hasCycle(struct ListNode *head);
}

bool hasCycle(struct ListNode *head)
{
    struct ListNode *p1,*p2;
    p1=p2=head;
    if(head==NULL)
        return false;
    while(p2->next!=NULL&&p2->next->next!=NULL)
    {
        p1=p1->next;
        p2=p2->next->next;
        if(p1==p2)
            return true;
    }
    return false;
}
