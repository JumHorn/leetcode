#include<list>
#include<unordered_map>
using namespace std;

class LFUCache {
	int c;//capacity
	int s;//size
	int minfreq;

	unordered_map<int,list<int>::iterator> iter;//key list iter
	unordered_map<int,list<int> > freq;//freq key list

	unordered_map<int,pair<int,int> > dict;//key {value freq}
public:
    LFUCache(int capacity) {
        c=capacity;
		s=0;
		minfreq=0;
    }
    
    int get(int key) {
		if(dict.find(key)==dict.end())
			return -1;

		freq[dict[key].second].erase(iter[key]);
		dict[key].second++;
		freq[dict[key].second].push_back(key);
		iter[key]=--freq[dict[key].second].end();
		if(freq[minfreq].size()==0)
			minfreq++;

		return dict[key].first;
    }
    
    void put(int key, int value) {
        if(c<=0)
            return;
		int tmp=get(key);
		if(tmp!=-1)
		{
			dict[key].first=value;
			return;
		}
		if(s>=c)
		{
			dict.erase(freq[minfreq].front());
			iter.erase(freq[minfreq].front());
			freq[minfreq].pop_front();
			s--;
		}
		freq[1].push_back(key);
		iter[key]=--freq[1].end();
		dict[key]=pair<int,int>(value,1);
		minfreq=1;
		s++;
	}
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
