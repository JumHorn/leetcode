#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class MajorityChecker {
	unordered_map<int,vector<int>> hashmap;
	vector<int> v;
public:
    MajorityChecker(vector<int>& arr):v(arr) {
        for(int i=0;i<(int)arr.size();i++)
			hashmap[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int threshold) {
		for(int i=0;i<7;i++)
		{
			int tmp=v[left+rand()%(right-left+1)];
			if(hashmap[tmp].size()>=threshold)
			{
				auto it1=lower_bound(hashmap[tmp].begin(),hashmap[tmp].end(),left);
				auto it2=upper_bound(hashmap[tmp].begin(),hashmap[tmp].end(),right);
				if(it2-it1>=threshold)
					return tmp;
			}
		}
		return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
