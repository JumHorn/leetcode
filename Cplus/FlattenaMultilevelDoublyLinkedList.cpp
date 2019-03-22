#include<iostream>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* node=head;
		if(node==NULL)
			return node;
		while(node!=NULL)
		{
			Node* tmp=node;
			node=node->next;
			flatten(tmp,node);
		}
		return head;
    }

	Node* flatten(Node* head,Node* tail)
	{
		if(head->child==NULL)
			return head;
		head->next=head->child;
		head->next->prev=head;
		Node* tmp2,*tmp1=head->child;
		head->child=NULL;
		while(tmp1->next!=NULL)
		{
			tmp2=tmp1;
			tmp1=tmp1->next;
			flatten(tmp2,tmp1);
		}
        tmp2=flatten(tmp1,tmp1->next);
		tmp2->next=tail;
		if(tail==NULL)
			return tmp2;
		tail->prev=tmp2;
		return tail;
	}
};
