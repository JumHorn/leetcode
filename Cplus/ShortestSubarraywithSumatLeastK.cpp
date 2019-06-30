#include<algorithm>
#include<numeric>
#include<vector>
#include<deque>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
		vector<int> sums(A.size()+1);
		deque<int> monoqueue;
		int res=INT_MAX;
		for(int i=1;i<=(int)A.size();i++)
			sums[i]=sums[i-1]+A[i-1];
		monoqueue.push_back(0);
		for(int i=1;i<=(int)A.size();i++)
		{
			while(!monoqueue.empty()&&sums[i]-sums[monoqueue.front()]>=K)
			{
				res=min(res,i-monoqueue.front());
				monoqueue.pop_front();
			}
			while(!monoqueue.empty()&&sums[i]<=sums[monoqueue.back()])
				monoqueue.pop_back();
			monoqueue.push_back(i);
		}
		return res==INT_MAX?-1:res;
    }
};