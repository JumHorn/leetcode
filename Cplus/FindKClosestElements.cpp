#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

/*
user defined comp must meets the requirement comp(a,b)=true then must comp(b,a)=false
*/

/*
heap comp is quiet different from sort
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		vector<int> res(k);
        for(int i=0;i<(int)arr.size();i++)
			arr[i]-=x;
		make_heap(arr.begin(),arr.end(),*this);

		for(int i=0;i<k;i++)
		{
			pop_heap(arr.begin(),arr.end()-i,*this);
			res[i]=*(arr.end()-i-1);
			res[i]+=x;
		}
        sort(res.begin(),res.end());
        return res;
    }

	bool operator()(int l,int r)
	{
        if(abs(l)==abs(r))
        {
            if(l<0&&r>0)
                return false;
            else
                return true;
        }
		return abs(l)>abs(r);
	}
};
