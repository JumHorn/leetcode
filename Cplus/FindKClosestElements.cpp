#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        for(int i=0;i<(int)arr.size();i++)
			arr[i]-=x;
		//sort(arr.begin(),arr.end(),*this);
		for(int i=0;i<(int)arr.size()-1;i++)
			for(int j=(int)arr.size()-1;j>i;j--)
			{
				if(!comp(arr[j-1],arr[j]))
					swap(arr[j-1],arr[j]);
			}

		vector<int> res(arr.begin(),arr.begin()+k);
        for(int i=0;i<(int)res.size();i++)
            res[i]+=x;
        sort(res.begin(),res.end());
        return res;
    }

	bool comp(int l,int r)
	{
		if(abs(l)==abs(r))
		{
			return l<=0;
		}
		return abs(l)<abs(r);
	}
};
