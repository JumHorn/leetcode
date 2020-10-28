#include <cstring>
using namespace std;

class MyHashMap
{
	typedef struct HashNode
	{
		int key;
		int value;
		struct HashNode *next;

		HashNode(int k, int v) : key(k), value(v), next(nullptr) {}
	} HashNode;

public:
	/** Initialize your data structure here. */
	MyHashMap() : HashTable(new HashNode *[HASH_TABLE_SIZE])
	{
		memset(HashTable, 0, sizeof(HashNode *) * HASH_TABLE_SIZE);
	}

	/** value will always be non-negative. */
	void put(int key, int value)
	{
		int bucket = (key & (HASH_TABLE_SIZE - 1));
		HashNode *head = HashTable[bucket];
		while (head)
		{
			if (head->key == key)
			{
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = new HashNode(key, value);
		head->next = HashTable[bucket];
		HashTable[bucket] = head;
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	int get(int key)
	{
		int bucket = (key & (HASH_TABLE_SIZE - 1));
		HashNode *head = HashTable[bucket];
		while (head)
		{
			if (head->key == key)
				break;
			head = head->next;
		}
		return head == nullptr ? -1 : head->value;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
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

private:
	HashNode **HashTable;
	static const int HASH_TABLE_SIZE = 1 << 10;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */