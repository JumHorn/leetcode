#include<vector>
#include<cmath>
using namespace std;

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
		return abs(l)<abs(r);
	}
};
