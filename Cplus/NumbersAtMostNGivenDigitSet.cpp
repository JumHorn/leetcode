#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
		int res=0,n=D.size();
    	vector<char> v(n);
		for(int i=0;i<n;i++)
			v[i]=D[i][0];
		string tmp=to_string(N);
		int len=tmp.length();
		for(int i=1;i<len;i++)
			res+=repeatA(i,n);
		for(int i=0;i<len;i++)
		{
			int j=0;
			while(j<n&&v[j]<tmp[i])
				j++;
			res+=j*repeatA(len-i-1,n);
			if(j>=n||v[j]!=tmp[i])
				break;
            if(v[j]==tmp[i]&&i==len-1)
                res++;
		}
		return res;
    }
	
	int repeatA(int m,int n)
	{
		if(m==0)
			return 1;
        int res=1;
		for(int i=0;i<m;i++)
			res*=n;
		return res;
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