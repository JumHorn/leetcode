#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    int superpalindromesInRange(string L, string R) {
		long long l=stoll(L),r=stoll(R),lr=sqrt(l),rr=sqrt(r);
		int res=0;
		for(long long i=lr;i<=rr;i++)
		{
			if(isPalindrome(i)&&isPalindrome(i*i))
				res++;
		}
		return res;
    }

	bool isPalindrome(long long x)
	{
		string tmp=to_string(x);
		int i=0,j=tmp.length()-1;
		while(i<j)
		{
			if(tmp[i++]!=tmp[j--])
				return false;
		}
		return true;
	}

	long long sqrtimproved(long long x)
	{
		long long lo=1,hi=x,mi;
		while(lo<hi)
		{
			mi=lo+(hi-lo)/2;
			if(mi*mi<x)
				lo=mi+1;
			else
				hi=mi;
		}
		return lo;
	}
};
