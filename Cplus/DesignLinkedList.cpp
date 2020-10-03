
class MyLinkedList
{
	struct LinkedList
	{
		int val;
		LinkedList *next;
		LinkedList(int x) : val(x), next(nullptr) {}
	};

public:
	/** Initialize your data structure here. */
	MyLinkedList()
	{
		head = tail = nullptr;
		size = 0;
	}

	~MyLinkedList()
	{
		LinkedList *tmp = head;
		while (head != nullptr)
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index)
	{
		if (index >= size || index < 0)
			return -1;
		LinkedList *node = head;
		while (--index >= 0)
			node = node->next;
		return node->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val)
	{
		LinkedList *node = new LinkedList(val);
		if (size == 0)
			head = tail = node;
		else
		{
			node->next = head;
			head = node;
		}
		++size;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val)
	{
		LinkedList *node = new LinkedList(val);
		if (size == 0)
			head = tail = node;
		else
		{
			tail->next = node;
			tail = node;
		}
		++size;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val)
	{
		if (index > size || index < 0)
			return;
		LinkedList *node = new LinkedList(val);
		if (size == 0 || index == 0)
			addAtHead(val);
		else if (size == index)
		{
			tail->next = node;
			tail = node;
		}
		else
		{
			LinkedList *tmp = head;
			while (--index != 0)
				tmp = tmp->next;
			node->next = tmp->next;
			tmp->next = node;
		}
		++size;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index)
	{
		if (index >= size || index < 0)
			return;
		LinkedList *node = head;
		if (index == 0)
		{
			head = head->next;
			delete node;
		}
		else
		{
			for (int i = 0; i < index - 1; ++i)
				node = node->next;
			if (index == size - 1)
				tail = node;
			LinkedList *tmp = node->next;
			node->next = tmp->next;
			delete tmp;
		}
		--size;
	}

private:
	LinkedList *head;
	LinkedList *tail;
	int size;
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