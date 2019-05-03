#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

/*
user defined comp must meets the requirement comp(a,b)=true then must comp(b,a)=false
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        for(int i=0;i<(int)arr.size();i++)
			arr[i]-=x;
		sort(arr.begin(),arr.end(),*this);
		vector<int> res(arr.begin(),arr.begin()+k);
        for(int i=0;i<(int)res.size();i++)
            res[i]+=x;
        sort(res.begin(),res.end());
        return res;
    }

	bool operator()(int l,int r)
	{
        if(abs(l)==abs(r))
        {
            if(l<0&&r>0)
                return true;
            else
                return false;
        }
		return abs(l)<abs(r);
	}
};
