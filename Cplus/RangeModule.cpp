#include<list>
#include<algorithm>
using namespace std;

class RangeModule {
	list<pair<int,int>> intervals;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
		for(list<pair<int,int>>::iterator iter=intervals.begin();iter!=intervals.end();)
		{
			if(iter->first>right)
			{
				intervals.insert(iter,{left,right});
				return;
			}
			if(iter->second<left)
			{
				++iter;
				continue;
			}
			left=min(left,iter->first);
			right=max(right,iter->second);
			intervals.erase(iter++);
		}
		intervals.push_back({left,right});
    }
    
    bool queryRange(int left, int right) {
		for(list<pair<int,int>>::iterator iter=intervals.begin();iter!=intervals.end();++iter)
		{
			if(left>=iter->first&&right<=iter->second)
				return true;
			if(iter->first>=right)
				return false;
		}
		return false;
    }
    
    void removeRange(int left, int right) {
		for(list<pair<int,int>>::iterator iter=intervals.begin();iter!=intervals.end();)
		{
			if(iter->first>=right)
				return;
			if(iter->second<=left)
			{
				++iter;
				continue;
			}
			if(iter->first>=left&&iter->second<=right)
				intervals.erase(iter++);
			else if(iter->first<left&&iter->second>right)
			{
				intervals.insert(iter,{iter->first,left});
				iter->first=right;
				++iter;
				return;
			}
			else if(iter->first<left)
			{
				iter->second=left;
				++iter;
			}
			else
			{
				iter->first=right;
				++iter;
			}
		}
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */