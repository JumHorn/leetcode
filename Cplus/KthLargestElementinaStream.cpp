#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class KthLargest {
	vector<int> v;
	int kth;
public:
    KthLargest(int k, vector<int> nums) {
        kth=k;
		v=nums;
		sort(v.begin(),v.end(),greater<int>());
		if(k<(int)v.size())
		    v.erase(v.begin()+k,v.end());
    }

    int add(int val) {
        if(v.empty())
        {
            v.push_back(val);
            return v[kth-1];
        }
        if(kth==v.size()&&val<=v.back())
            return v[kth-1];
		int i=0,j=v.size()-1;
		while(j>=i)
		{
			int mid=(j-i)/2+i+(j-i)%2;
			if(val==v[mid])
			{
				v.insert(v.begin()+mid,val);
                if(kth<(int)v.size())
				    v.pop_back();
				return v[kth-1];
			}
			if(val>v[mid])
			{
                if(i==j)
                {
                    v.insert(v.begin()+j,val);
                    if(kth<(int)v.size())
		                v.pop_back();
                    return v[kth-1];
                }
				j=mid-1;
			}
			else
			{
                if(i==j)
                {
                    v.insert(v.begin()+j+1,val);
                    if(kth<(int)v.size())
		                v.pop_back();
                    return v[kth-1];
                }
				i=mid+1;
			}
		}
        v.insert(v.begin()+i,val);
        if(kth<(int)v.size())
            v.pop_back();
        return v[kth-1];
    }
};
