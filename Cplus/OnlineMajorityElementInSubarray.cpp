#include<vector>
using namespace std;

class MajorityChecker {
	vector<int> v;
public:
    MajorityChecker(vector<int>& arr) {
        v=arr;
    }
    
    int query(int left, int right, int threshold) {
		int count=0,res=-1;
        for(int i=left;i<=right;i++)
		{
			if(count==0)
			{
				res=v[i];
				count=1;
			}
			else if(res!=v[i])
				count--;
			else
				count++;
		}
		count=0;
		for(int i=left;i<=right;i++)
			if(res==v[i])
				count++;
		if(count<threshold)
			return -1;
		return res;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
