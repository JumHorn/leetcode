#include <map>
#include <string>
using namespace std;

class TimeMap
{
public:
	/** Initialize your data structure here. */
	TimeMap()
	{
	}

	void set(string key, string value, int timestamp)
	{
		m[key][timestamp] = value;
	}

	string get(string key, int timestamp)
	{
		if (m.find(key) == m.end())
			return "";
		auto &tmp = m[key];
		if (tmp.begin()->first > timestamp)
			return "";
		auto iter = tmp.upper_bound(timestamp);
		if (iter != tmp.begin())
			--iter;
		return iter->second;
	}

private:
	map<string, map<int, string>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */