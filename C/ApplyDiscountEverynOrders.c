#include <stdlib.h>
#include <string.h>

// HASH
#define HASH_TABLE_SIZE (1 << 10)
typedef struct HashNode
{
	int key;
	int value;
	struct HashNode *next;
} HashNode;

HashNode *HashTable[HASH_TABLE_SIZE];

void hash_init()
{
	memset(HashTable, 0, sizeof(HashTable));
}

void hash_release()
{
	for (int i = 0; i < HASH_TABLE_SIZE; ++i)
	{
		HashNode *node = HashTable[i];
		while (node)
		{
			HashNode *deletenode = node;
			node = node->next;
			free(deletenode);
		}
	}
}

HashNode *hash_createNode(int key, int value)
{
	HashNode *node = (HashNode *)malloc(sizeof(HashNode));
	node->key = key;
	node->value = value;
	node->next = NULL;
	return node;
}

void hash_set(int key, int value)
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
	head = hash_createNode(key, value);
	head->next = HashTable[bucket];
	HashTable[bucket] = head;
}

HashNode *hash_get(int key)
{
	int bucket = (key & (HASH_TABLE_SIZE - 1));
	HashNode *head = HashTable[bucket];
	while (head)
	{
		if (head->key == key)
			break;
		head = head->next;
	}
	return head;
}
/********end of HASH********/

typedef struct
{
	int count;
	int n;
	int discount;
} Cashier;

Cashier *cashierCreate(int n, int discount, int *products, int productsSize, int *prices, int pricesSize)
{
	hash_init();
	for (int i = 0; i < productsSize; ++i)
		hash_set(products[i], prices[i]);
	Cashier *cashier = (Cashier *)malloc(sizeof(Cashier));
	cashier->count = 0;
	cashier->discount = discount;
	cashier->n = n;
	return cashier;
}

double cashierGetBill(Cashier *obj, int *product, int productSize, int *amount, int amountSize)
{
	double res = 0.0;
	for (int i = 0; i < productSize; ++i)
		res += hash_get(product[i])->value * amount[i];
	if (++obj->count == obj->n)
	{
		obj->count = 0;
		res = res - (res * obj->discount) / 100;
	}
	return res;
}

void cashierFree(Cashier *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your Cashier struct will be instantiated and called as such:
 * Cashier* obj = cashierCreate(n, discount, products, productsSize, prices, pricesSize);
 * double param_1 = cashierGetBill(obj, product, productSize, amount, amountSize);

 * cashierFree(obj);
*/