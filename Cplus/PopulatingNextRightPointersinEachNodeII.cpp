#include<iostream>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
		Node* helper=new Node();        
		Node* p=helper;
		Node* tmp=root;
        helper->next=NULL;
		while(tmp!=NULL)
		{
			if(tmp->left!=NULL)
			{
				p->next=tmp->left;
				p=p->next;
			}
			if(tmp->right!=NULL)
			{
				p->next=tmp->right;
				p=p->next;
			}
			if(tmp->next!=NULL)
				tmp=tmp->next;
			else
			{
				tmp=helper->next;
				helper->next=NULL;
				p=helper;
			}
		}
		return root;
    }
};
