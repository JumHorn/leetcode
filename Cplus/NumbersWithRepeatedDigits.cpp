#include<string>
#include<cmath>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int numDupDigitsAtMostN(int N) {
		string tmp=to_string(N+1);
		int len=tmp.length(),res=0;
		for(int i=1;i<len;i++)
			res+=9*A(i-1,9);
		unordered_set<char> s;
        s.insert(tmp[0]);
        res+=(tmp[0]-'1')*A(len-1,9);
		for(int i=1;i<len;i++)
		{
			for(char c='0';c<tmp[i];c++)
                if(s.find(c)==s.end())
				    res+=A(len-i-1,10-i-1);
			if(s.find(tmp[i])==s.end())
				s.insert(tmp[i]);
			else
				break;
		}
		return N-res;
    }

	int A(int m,int n)
	{
		if(m==0)
			return 1;
		if(m==1)
			return n;
		return (n-m+1)*A(m-1,n);
	}
};