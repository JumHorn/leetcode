#include<map>
#include<algorithm>
using namespace std;

//求所有book事件的最大值

class MyCalendarThree {
private:
	map<int,int> boundary;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        boundary[start]++;
		boundary[end]--;
		int active=0,res=0;
		for(auto& n:boundary)
		{
			active+=n.second;
			res=max(res,active);
		}
		return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
