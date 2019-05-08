#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
		int n=A.size();
		priority_queue<pair<double,pair<int,int> > > q;
		if(K==1)
			return vector<int>({A.front(),A.back()});
		q.push({-1.0*A[0]/A[n-2],{0,n-2}});
		for(int i=1;i<n;i++)
		{
			q.push({-1.0*A[i]/A.back(),{i,n-1}});
		}
        int x,y;
		while(--K!=0)
		{
			x=q.top().second.first;
			y=q.top().second.second;
            q.pop();
			if(x<=y-1)
				q.push({-1.0*A[x]/A[y-1],{x,y-1}});
		}
		return vector<int>({A[x],A[y]});
    }
};
