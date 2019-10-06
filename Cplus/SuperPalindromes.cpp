#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    int superpalindromesInRange(string L, string R) {
		long long l=stoll(L),r=stoll(R);
		int res=0,magic=1e5;
		for(long long i=1;i<magic;i++)
		{
			string tmp=to_string(i),retmp=tmp;
			reverse(retmp.begin(),retmp.end());
			tmp+=retmp;
			long long v=stoll(tmp);
			v*=v;
			if(v>r)
				break;
			if(v>=l&&isPalindrome(v))
				res++;
		}
		for(long long i=1;i<magic;i++)
		{
			string tmp=to_string(i),retmp=tmp.substr(0,tmp.length()-1);
			reverse(retmp.begin(),retmp.end());
			tmp+=retmp;
			long long v=stoll(tmp);
			v*=v;
			if(v>r)
				break;
			if(v>=l&&isPalindrome(v))
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
};
