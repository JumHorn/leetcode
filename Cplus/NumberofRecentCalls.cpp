#include<vector>
using namespace std;

class RecentCounter {
	vector<int> v;
	int last;
public:
    RecentCounter() {
        last=0;
    }
    
    int ping(int t) {
        v.push_back(t);
		while(v[last]<t-3000)
			last++;
		return v.size()-last;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
