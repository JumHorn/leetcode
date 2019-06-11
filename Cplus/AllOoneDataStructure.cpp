#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<climits>
using namespace std;

class AllOne {
	unordered_map<string,int> m1;
	map<int,unordered_set<string> > m2;

public:
    /** Initialize your data structure here. */
    AllOne() {
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
		int tmp=m1[key];
		m2[tmp].erase(key);
		if(m2[tmp].empty())
			m2.erase(tmp);
		tmp=++m1[key];
		m2[tmp].insert(key);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(m1.find(key)==m1.end())
			return;
		int tmp=m1[key];
		m2[tmp].erase(key);
		if(m2[tmp].empty())
			m2.erase(tmp);
		if(m1[key]==1)
			m1.erase(key);
		else
			m2[--m1[key]].insert(key);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(m1.empty())
			return "";
		return *(--m2.end())->second.begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
		if(m1.empty())
			return "";
        return *(m2.begin()->second.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
