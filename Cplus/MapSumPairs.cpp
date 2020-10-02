#include <string>
#include <unordered_map>
using namespace std;

class MapSum
{
public:
	/** Initialize your data structure here. */
	MapSum()
	{
	}

	void insert(string key, int val)
	{
		int delta = val - m[key];
		m[key] = val;
		string prefix;
		for (auto c : key)
		{
			prefix += c;
			prefixsum[prefix] += delta;
		}
	}

	int sum(string prefix)
	{
		return prefixsum[prefix];
	}

private:
	unordered_map<string, int> m;		  //{str,value}
	unordered_map<string, int> prefixsum; //{prefix,sum}
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */