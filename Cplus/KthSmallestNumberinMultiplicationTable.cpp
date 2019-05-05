#include<algorithm>
using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
		int high=m*n,low=1,mid,cnt,tmp;
		while(low<high)
		{
			cnt=0;
			mid=(high-low)/2+low;
            tmp=n;
			for(int i=0;i<m;i++)
			{
                while(tmp >=1 && (i+1)*tmp > mid) tmp--;
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
