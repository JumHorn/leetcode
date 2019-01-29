#include<iostream>
using namespace std;

class MyLinkedList {
	struct LinkedList
	{
		int val;
		LinkedList* next;
		LinkedList(int x):val(x),next(NULL){}
	};

	LinkedList* head;
	LinkedList* tail;
	int size;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head=NULL;
		tail=NULL;
		size=0;
    }

	~MyLinkedList()
	{
		LinkedList* tmp=head;
		while(head!=NULL)
		{
			tmp=head;
			head=head->next;
			delete tmp;
		}
	}
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=size||index<0)
			return -1;
		LinkedList* tmp=head;
		while(index--!=0)
			tmp=tmp->next;
		return tmp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedList* tmp=new LinkedList(val);
		if(size==0)
		{
			head=tail=tmp;
		}
		else
		{
			tmp->next=head;
			head=tmp;
		}
		size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedList* tmp=new LinkedList(val);
		if(size==0)
		{
			head=tail=tmp;
		}
		else
		{
			tail->next=tmp;
			tail=tmp;
		}
		size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>size||index<0)
			return;
        LinkedList* tmp=new LinkedList(val);
		if(size==0)
		{
			head=tail=tmp;
		}
		else if(size==index)
		{
			tail->next=tmp;
			tail=tmp;
		}
		else
		{
			LinkedList* t=head;
			if(index==0)
			{
				tmp->next=head;
				head=tmp;
			}
			else
			{
				while(--index!=0)
					t=t->next;
				tmp->next=t->next;
				t->next=tmp;
			}
		}
		size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=size||index<0)
			return;
		LinkedList* tmp=head;
		if(index==0)
		{
			head=head->next;
			delete tmp;
		}
		else
		{
			int s=index;
			while(--index!=0)
				tmp=tmp->next;
            if(s==size-1)
            {
                tail=tmp;
            }
			LinkedList* t=tmp->next;
			tmp->next=t->next;
			delete t;
		}
		size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
