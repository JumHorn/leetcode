#include<list>
#include<map>
using namespace std;

class FreqStack {
	map<int,int> freq;
	list<int> s;
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        ++freq[x];
		s.push_front(x);
    }
    
    int pop() {
		int m=-1,val;
        for(map<int,int>::iterator it=freq.begin();it!=freq.end();++it)
			if(it->second>m)
				m=it->second;
		for(list<int>::iterator it=s.begin();it!=s.end();++it)
		{
			if(freq[*it]==m)
			{
				val=*it;
				s.erase(it);
				break;
			}
		}
		--freq[val];
		return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
