#include <cstring>
using namespace std;

class MyHashSet
{
	typedef struct HashNode
	{
		int key;
		struct HashNode *next;

		HashNode(int k) : key(k), next(nullptr) {}
	} HashNode;

public:
	/** Initialize your data structure here. */
	MyHashSet() : HashTable(new HashNode *[HASH_TABLE_SIZE])
	{
		memset(HashTable, 0, sizeof(HashNode *) * HASH_TABLE_SIZE);
	}

	void add(int key)
	{
		int bucket = (key & (HASH_TABLE_SIZE - 1));
		HashNode *head = HashTable[bucket];
		while (head)
		{
			if (head->key == key)
				return;
			head = head->next;
		}
		head = new HashNode(key);
		head->next = HashTable[bucket];
		HashTable[bucket] = head;
	}

	void remove(int key)
	{
		int bucket = (key & (HASH_TABLE_SIZE - 1));
		HashNode **head = &HashTable[bucket];
		while (*head)
		{
			if ((*head)->key == key)
			{
				*head = (*head)->next;
				break;
			}
			head = &(*head)->next;
		}
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key)
	{
		int bucket = (key & (HASH_TABLE_SIZE - 1));
		HashNode *head = HashTable[bucket];
		while (head)
		{
			if (head->key == key)
				return true;
			head = head->next;
		}
		return false;
	}

private:
	HashNode **HashTable;
	static const int HASH_TABLE_SIZE = 1 << 10;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */