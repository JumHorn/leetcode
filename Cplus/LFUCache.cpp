#include <list>
#include <tuple>
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
		auto &keyinfo = dict[key];
		int f = std::get<1>(keyinfo)++;
		freq[f].erase(std::get<2>(keyinfo));
		freq[++f].push_front(key);
		std::get<2>(keyinfo) = freq[f].begin();
		if (freq[minfreq].empty())
			++minfreq;
		return std::get<0>(keyinfo);
	}

	void put(int key, int value)
	{
		if (c <= 0)
			return;
		if (get(key) != -1)
		{
			std::get<0>(dict[key]) = value;
			return;
		}
		if ((int)dict.size() >= c)
		{
			dict.erase(freq[minfreq].back());
			freq[minfreq].pop_back();
		}
		freq[1].push_front(key);
		dict[key] = {value, 1, freq[1].begin()};
		minfreq = 1;
	}

private:
	int c; //capacity
	int minfreq;
	//freq key list (front key is latest)
	unordered_map<int, list<int>> freq;
	//{key {value,freq,postion of freq list}}
	unordered_map<int, tuple<int, int, list<int>::iterator>> dict;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */