#include<algorithm>
using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
		int high=m*n,low=1,mid,res=high,cnt,tmp;
		while(low<high)
		{
			cnt=0;
			mid=(high-low)/2+low;
			for(int i=0;i<m;i++)
			{
				tmp=min(mid/(i+1),n);
				if(tmp==0)
					break;
				cnt+=tmp;
			}
			if(cnt>=k)
				res=high=mid;
			else
				low=mid+1;
		}
		return res;		
    }
};


