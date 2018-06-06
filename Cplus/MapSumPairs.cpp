#include<iostream>
#include<string>
#include<map>
using namespace std;

class MapSum {
public:
    /** Initialize your data structure here. */

	map<string,int> dictionary;

    MapSum() {
        
    }
    
    void insert(string key, int val) {
        dictionary[key]=val;
    }
    
    int sum(string prefix) {
        int res=0;
		for(map<string,int>::iterator iter=dictionary.begin();iter!=dictionary.end();iter++)
		{
			if(stringCompare(iter->first,prefix))
			{
				res+=iter->second;
			}
		}
		return res;
    }

	bool stringCompare(const string& key,const string& prefix)
	{
		if(key.length()<prefix.length())
		{
			return false;
		}
		for(int i=0;i<prefix.length();i++)
		{
			if(key[i]!=prefix[i])
			{
				return false;
			}
		}
		return true;
	}
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
