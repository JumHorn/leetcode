#include <algorithm>
using namespace std;

class Skiplist
{
public:
	Skiplist()
	{
		root = new LinkedList(0);
		// root->child = new LinkedList(0);
		// root->child->child = new LinkedList(0);
	}

	bool search(int target)
	{
		LinkedList *tmp1 = root;
		while (tmp1 != nullptr && target - tmp1->val >= 1000)
			tmp1 = tmp1->next;
		if (tmp1 == nullptr)
			return false;
		LinkedList *tmp2 = tmp1->child;
		while (tmp2 != nullptr && target - tmp2->val >= 100)
			tmp2 = tmp2->next;
		if (tmp2 == nullptr)
			return false;
		LinkedList *tmp3 = tmp2->child;
		while (tmp3 != nullptr && target - tmp3->val >= 10)
			tmp3 = tmp3->next;
		if (tmp3 == nullptr)
			return false;
		LinkedList *tmp4 = tmp3->child;
		while (tmp4 != nullptr)
		{
			if (tmp4->val == target)
				return true;
			tmp4 = tmp4->next;
		}
		return false;
	}

	void add(int num)
	{
		int i = 1;
		LinkedList *tmp1 = root;
		while (num >= i * 1000)
		{
			if (tmp1->next == nullptr)
				tmp1->next = new LinkedList(i * 1000);
			tmp1 = tmp1->next;
			++i;
		}
		LinkedList *tmp2 = tmp1->child;
		if (tmp2 == nullptr)
			tmp2 = tmp1->child = new LinkedList(tmp1->val);
		int val = tmp1->val;
		i = 1;
		while (num >= val + i * 100)
		{
			if (tmp2->next == nullptr)
				tmp2->next = new LinkedList(val + i * 100);
			tmp2 = tmp2->next;
			++i;
		}
		LinkedList *tmp3 = tmp2->child;
		if (tmp3 == nullptr)
			tmp3 = tmp2->child = new LinkedList(tmp2->val);
		val = tmp3->val;
		i = 1;
		while (num >= val + i * 10)
		{
			if (tmp3->next == nullptr)
				tmp3->next = new LinkedList(val + i * 10);
			tmp3 = tmp3->next;
			++i;
		}
		LinkedList *tmp4 = tmp3->child;
		if (tmp4 == nullptr)
		{
			tmp3->child = new LinkedList(num);
			return;
		}
		if (tmp4->val >= num)
		{
			LinkedList *newhead = new LinkedList(num);
			newhead->next = tmp4;
			tmp3->child = newhead;
			return;
		}
		while (tmp4->next != nullptr)
		{
			if (num <= tmp4->next->val)
				break;
			tmp4 = tmp4->next;
		}
		LinkedList *newnode = new LinkedList(num);
		newnode->next = tmp4->next;
		tmp4->next = newnode;
	}

	bool erase(int num)
	{
		LinkedList *tmp1 = root;
		while (tmp1 != nullptr && num - tmp1->val >= 1000)
			tmp1 = tmp1->next;
		if (tmp1 == nullptr)
			return false;
		LinkedList *tmp2 = tmp1->child;
		while (tmp2 != nullptr && num - tmp2->val >= 100)
			tmp2 = tmp2->next;
		if (tmp2 == nullptr)
			return false;
		LinkedList *tmp3 = tmp2->child;
		while (tmp3 != nullptr && num - tmp3->val >= 10)
			tmp3 = tmp3->next;
		if (tmp3 == nullptr)
			return false;
		LinkedList *tmp4 = tmp3->child;
		if (tmp4 == nullptr)
			return false;
		if (tmp4->val == num)
		{
			tmp3->child = tmp4->next;
			return true;
		}
		while (tmp4->next != nullptr)
		{
			if (tmp4->next->val == num)
			{
				tmp4->next = tmp4->next->next;
				return true;
			}
			tmp4 = tmp4->next;
		}
		return false;
	}

private:
	struct LinkedList
	{
		int val;
		LinkedList *next;
		LinkedList *child;
		LinkedList(int v) : val(v), next(nullptr), child(nullptr) {}
	};

	LinkedList *root;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */