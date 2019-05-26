#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
		int n=ratings.size();
		vector<int> res(n,1);
		for(int i=1;i<n;i++)
			if(ratings[i-1]<ratings[i])
				res[i]+=res[i-1];

		for(int i=n-1;i>0;i--)
			if(ratings[i-1]>ratings[i])
				res[i-1]=max(res[i-1],res[i]+1);

		return accumulate(res.begin(),res.end(),0);
	}
};
