#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class AllOne
{
public:
	/** Initialize your data structure here. */
	AllOne()
	{
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key)
	{
		auto iter = m.find(key);
		if (iter == m.end())
		{
			if (data.empty() || data.front().first != 1)
				data.push_front({1, {key}});
			else
				data.front().second.insert(key);
			m[key] = data.begin();
		}
		else
		{
			int freq = iter->second->first;
			auto after = iter->second;
			++after;
			iter->second->second.erase(key);
			if (iter->second->second.empty())
				data.erase(iter->second);
			if (after == data.end() || after->first != freq + 1)
				m[key] = data.insert(after, {freq + 1, {key}});
			else
			{
				after->second.insert(key);
				m[key] = after;
			}
		}
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key)
	{
		auto iter = m.find(key);
		if (iter == m.end())
			return;
		auto iter1 = iter->second;
		int freq = iter->second->first;
		if (freq != 1)
		{
			auto before = iter->second;
			--before;
			if (iter->second == data.begin() || before->first != freq - 1)
				m[key] = data.insert(iter->second, {freq - 1, {key}});
			else
			{
				before->second.insert(key);
				m[key] = before;
			}
		}
		else
			m.erase(key);
		iter1->second.erase(key);
		if (iter1->second.empty())
			data.erase(iter1);
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey()
	{
		if (data.empty())
			return "";
		return *data.back().second.begin();
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey()
	{
		if (data.empty())
			return "";
		return *data.front().second.begin();
	}

private:
	list<pair<int, unordered_set<string>>> data;
	unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> m;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */