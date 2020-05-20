#include <list>
#include <unordered_map>
using namespace std;

class LFUCache
{
public:
	LFUCache(int capacity)
	{
		c = capacity;
		minfreq = 0;
	}

	int get(int key)
	{
		if (dict.find(key) == dict.end())
			return -1;
		freq[dict[key].second].erase(iter[key]);
		freq[++dict[key].second].push_back(key);
		iter[key] = --freq[dict[key].second].end();
		if (freq[minfreq].empty())
			minfreq++;
		return dict[key].first;
	}

	void put(int key, int value)
	{
		if (c <= 0)
			return;
		if (get(key) != -1)
		{
			dict[key].first = value;
			return;
		}
		if ((int)dict.size() >= c)
		{
			dict.erase(freq[minfreq].front());
			iter.erase(freq[minfreq].front());
			freq[minfreq].pop_front();
		}
		freq[1].push_back(key);
		iter[key] = --freq[1].end();
		dict[key] = {value, 1};
		minfreq = 1;
	}

private:
	int c; //capacity
	int minfreq;

	unordered_map<int, list<int>::iterator> iter; //key list iter
	unordered_map<int, list<int>> freq;			  //freq key list

	unordered_map<int, pair<int, int>> dict; //key {value freq}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
