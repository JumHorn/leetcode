#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class AllOne
{
public:
	/** Initialize your bucket structure here. */
	AllOne()
	{
	}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key)
	{
		// If the key doesn't exist, insert it with value 0.
		if (m.find(key) == m.end())
			m[key] = bucket.insert(bucket.begin(), {0, {key}});
		// Insert the key in next bucket and update the lookup.
		auto next = m[key], cur = next++;
		if (next == bucket.end() || next->first > cur->first + 1)
			next = bucket.insert(next, {cur->first + 1, {}});
		next->second.insert(key);
		m[key] = next;
		// Remove the key from its old bucket.
		cur->second.erase(key);
		if (cur->second.empty())
			bucket.erase(cur);
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the bucket structure. */
	void dec(string key)
	{
		// If the key doesn't exist, just leave.
		auto iter = m.find(key);
		if (iter == m.end())
			return;
		// Maybe insert the key in previous bucket and update the lookup.
		auto pre = iter->second, cur = pre--;
		m.erase(key);
		if (cur->first > 1)
		{
			if (cur == bucket.begin() || pre->first < cur->first - 1)
				pre = bucket.insert(cur, {cur->first - 1, {}});
			pre->second.insert(key);
			m[key] = pre;
		}
		// Remove the key from its old bucket.
		cur->second.erase(key);
		if (cur->second.empty())
			bucket.erase(cur);
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey()
	{
		return m.empty() ? "" : *bucket.back().second.begin();
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey()
	{
		return m.empty() ? "" : *bucket.front().second.begin();
	}

private:
	list<pair<int, unordered_set<string>>> bucket;							   //{count,keys}
	unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> m; //{keys,buckets iter}
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */