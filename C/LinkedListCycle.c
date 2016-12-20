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
    p2=head->next;
    while(p2!=NULL)
    {
        p1=head;
        if(p2->next==p2)
        {
            return true;
        }
        while(p1!=p2)
        {
            if(p2->next==p1)
            {
                return true;
            }
            p1=p1->next;
        }
        p2=p2->next;
    }
    return false;
}
