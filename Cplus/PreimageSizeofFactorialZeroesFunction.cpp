#include<climits>
using namespace std;

class Solution {
public:
    int preimageSizeFZF(int K) {
		int lo=0,hi=INT_MAX;
		while(lo<hi)
		{
			int mi=(hi-lo)/2+lo;
			int zero=getSuffixZero(mi);
			if(zero<K)
				lo=mi+1;
			else
				hi=mi;
		}
		if(getSuffixZero(lo)==K)
			return 5;
		return 0;
    }

	int getSuffixZero(int n)
	{
		int res=0,d=5,t=n/d;
		while(true)
		{
			res+=t;
            n/=d;
			t=n/d;
            if(t==1||t==0)
            {
                res+=t;
                break;
            }
		}
		return res;
	}
};
