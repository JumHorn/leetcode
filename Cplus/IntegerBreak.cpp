#include<cmath>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
		if(n==3)
			return 2;
		int max=1;
		for(int i=0;i<n/2;i++)
		{
			int last=(n%(i+1))*(i+1);
			if(n%(i+1)==0)
				last=i+1;
			if(n%(i+1)==1)
				last=i+2;
			int tmp=pow(i+1,n/(i+1)-1)*last;
			if(tmp>max)
			{
				max=tmp;
			}
		}
		return max;
    }
};
