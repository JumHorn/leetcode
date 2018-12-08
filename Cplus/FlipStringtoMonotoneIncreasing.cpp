#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string S) {
		int res=getZero(S);        
		if(res==0)
			return 0;
		return minFlips(S,0,res);
    }

	int minFlips(const string& s,int start,int ones)
	{
		for(int i=start;i<s.length();i++)
			if(s[i]=='0')
				ones--;
			else
				return min(ones,minFlips(s,i+1,ones)+1);
		return ones;
	}

	int getZero(const string& s)
	{
		int total=0;
		for(int i=0;i<s.length();i++)
			if(s[i]=='0')
				total++;
		return total;
	}
};
