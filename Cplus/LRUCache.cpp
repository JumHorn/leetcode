#include <list>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
	LRUCache(int capacity)
	{
		size = capacity;
	}

	int get(int key)
	{
		auto it = m.find(key);
		if (it == m.end())
			return -1;
		int value = it->second->second;
		//Transfers elements to head
		data.splice(data.begin(), data, it->second);
		return value;
	}

	void put(int key, int value)
	{
		auto it = m.find(key);
		if (it != m.end())
		{
			it->second->second = value;
			data.splice(data.begin(), data, it->second);
			return;
		}

		if (data.size() >= size)
		{
			m.erase(data.back().first);
			data.pop_back();
		}
		data.push_front({key, value});
		m[key] = data.begin();
	}

private:
	list<pair<int, int>> data; //{key,value}
	unordered_map<int, list<pair<int, int>>::iterator> m;
	int size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */