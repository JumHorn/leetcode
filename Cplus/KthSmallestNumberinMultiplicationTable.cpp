#include<algorithm>
using namespace std;

/*
tmp=min(mid/(i+1),n); this is much faster than cnt+=min(mid/(i+1),n);
cnt+=tmp;
*/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
		int high=m*n,low=1,mid,cnt,tmp;
		while(low<high)
		{
			cnt=0;
			mid=(high-low)/2+low;
			for(int i=0;i<m;i++)
			{
				tmp=min(mid/(i+1),n);
				cnt+=tmp;
			}
			if(cnt>=k)
				high=mid;
			else
				low=mid+1;
		}
		return high;
    }
};
