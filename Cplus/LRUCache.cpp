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
		if (m.find(key) == m.end())
			return -1;
		int value = m[key]->second;
		data.erase(m[key]);
		data.push_front({key, value});
		m[key] = data.begin();
		return value;
	}

	void put(int key, int value)
	{
		if (m.find(key) != m.end())
			data.erase(m[key]);
		else
		{
			if (data.size() >= size)
			{
				m.erase(data.back().first);
				data.pop_back();
			}
		}
		data.push_front({key, value});
		m[key] = data.begin();
	}

private:
	list<pair<int, int>> data;
	unordered_map<int, list<pair<int, int>>::iterator> m;
	int size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */