#include<stdlib.h>
#include<string.h>

#define HASHSIZE (1<<14)
#define OPENADDRESS 11

typedef struct {
    int valarr[HASHSIZE];
} MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet* hashset=(MyHashSet*)malloc(sizeof(MyHashSet)*1);
	memset(hashset,-1,sizeof(MyHashSet));
	return hashset;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int address=key;
	while(obj->valarr[address&(HASHSIZE-1)]>=0&&obj->valarr[address&(HASHSIZE-1)]!=key)
		address+=OPENADDRESS;
	obj->valarr[address&(HASHSIZE-1)]=key;
}

void myHashSetRemove(MyHashSet* obj, int key) {
  	int address=key;
	while(obj->valarr[address&(HASHSIZE-1)]!=key&&obj->valarr[address&(HASHSIZE-1)]!=-1)
	{
		address+=OPENADDRESS;
		if((address&(HASHSIZE-1))==(key&(HASHSIZE-1)))
			break;
	}
	if(obj->valarr[address&(HASHSIZE-1)]==key)
		obj->valarr[address&(HASHSIZE-1)]=-2;
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    int address=key;
	while(obj->valarr[address&(HASHSIZE-1)]!=-1)
	{
		if(obj->valarr[address&(HASHSIZE-1)]==key)
			return true;
		address+=OPENADDRESS;
	}
	return false;
}

void myHashSetFree(MyHashSet* obj) {
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
