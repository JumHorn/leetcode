#include<list>
#include<unordered_map>
using namespace std;

class LRUCache {
	int c;
	list<pair<int,int> > l;
	unordered_map<int,list<pair<int,int> >::iterator> dict;
public:
    LRUCache(int capacity) {
        c=capacity;
    }
    
    int get(int key) {
        if(dict.find(key)!=dict.end())
		{
			l.push_back({key,dict[key]->second});
			l.erase(dict[key]);
			dict[key]=--l.end();
			return dict[key]->second;
		}
		return -1;
    }
    
    void put(int key, int value) {
		if(dict.find(key)!=dict.end())
		{
			l.push_back({key,value});
			l.erase(dict[key]);
			dict[key]=--l.end();
			return;
		}
        if((int)l.size()>=c)
		{
			dict.erase(l.front().first);
			l.pop_front();
		}
		l.push_back({key,value});
		dict[key]=--l.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
