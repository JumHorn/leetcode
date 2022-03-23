#include <algorithm>
#include <cmath>
using namespace std;

class Skiplist
{
public:
	Skiplist()
	{
		sentinel = new SkiplistNode(0);
	}

	bool search(int target)
	{
		SkiplistNode *node = sentinel;
		for (int i = SKIPLIST_MAXLEVEL - 1; i >= 0; --i)
		{
			while (node->level[i] != nullptr && node->level[i]->val < target)
				node = node->level[i];
		}
		return node->level[0] != nullptr && node->level[0]->val == target;
	}

	void add(int num)
	{
		SkiplistNode *node[SKIPLIST_MAXLEVEL + 1]; //search path for every level node
		node[SKIPLIST_MAXLEVEL] = sentinel;
		for (int i = SKIPLIST_MAXLEVEL - 1; i >= 0; --i)
		{
			node[i] = node[i + 1];
			while (node[i]->level[i] != nullptr && node[i]->level[i]->val < num)
				node[i] = node[i]->level[i];
		}
		//already exist
		if (node[0]->level[0] != nullptr && node[0]->level[0]->val == num)
			return;
		int level = randomLevel();
		SkiplistNode *new_node = new SkiplistNode(num);
		for (int i = 0; i < level; ++i)
		{
			new_node->level[i] = node[i]->level[i];
			node[i]->level[i] = new_node;
		}
	}

	bool erase(int num)
	{
		SkiplistNode *node[SKIPLIST_MAXLEVEL + 1]; //search path for every level node
		node[SKIPLIST_MAXLEVEL] = sentinel;
		for (int i = SKIPLIST_MAXLEVEL - 1; i >= 0; --i)
		{
			node[i] = node[i + 1];
			while (node[i]->level[i] != nullptr && node[i]->level[i]->val < num)
				node[i] = node[i]->level[i];
		}
		//not exist
		if (node[0]->level[0] != nullptr && node[0]->level[0]->val != num)
			return false;
		SkiplistNode *remove_node = node[0]->level[0];
		for (int i = 0; i < SKIPLIST_MAXLEVEL && remove_node->level[i] != nullptr; ++i)
			node[i]->level[i] = remove_node->level[i];
		return true;
	}

private:
	static const int SKIPLIST_MAXLEVEL = 4;
	//Definition for skip list node.
	struct SkiplistNode
	{
		int val;
		//可以按需求分配，即当randomLevel()得出结果时再分配
		//SkiplistNode *level;
		SkiplistNode *level[SKIPLIST_MAXLEVEL];
		SkiplistNode(int x) : val(x), level()
		{
			for (int i = 0; i < SKIPLIST_MAXLEVEL; ++i)
				level[i] = nullptr;
		}
	};

	SkiplistNode *sentinel; //first node without data
	int size;				//node count of the skiplist

private:
	/* Returns a random level for the new skiplist node.
 	 * The return value is a powerlaw-alike distribution where higher
 	 * levels are less likely to be returned. from redis source code*/
	int randomLevel()
	{
		int level = 1;
		while ((random() & 0xFFFF) < (0.25 * 0xFFFF))
			level += 1;
		return (level < SKIPLIST_MAXLEVEL) ? level : SKIPLIST_MAXLEVEL;
	}
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */