#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string orderlyQueue(string S, int K) {
		int N=S.length();	        
		if(K>=N)
		{
			sort(S.begin(),S.end());
			return S;
		}
		for(int i=0;i<K;i++)
		{
			auto iter=min_element(S.begin()+i,S.end());
			int d=distance(S.begin(),iter);
			for(int j=i;j<N;j++)
			{
				if(j!=d&&S[j]==S[d])
				{
					if(i==K-1)
					{
						if(minReverse(S,N-i,j,d))
							d=j;
					}
					else
					{
						if(!minReverse(S,N-i,j,d))
							d=j;
					}
				}
			}
			strReverse(S,i,d);
		}
		return S;
    }

	void strReverse(string& s,int i,int d)
	{
		string tmp(s.substr(i,d-i));
        copy(s.begin()+d,s.end(),s.begin()+i);
		copy(tmp.begin(),tmp.end(),s.begin()+i+s.length()-d);
	}

	bool minReverse(const string& s,int n,int i,int j)
	{
		for(int k=0;k<n;k++)
		{
			if(s[(i+k)%n]!=s[(j+k)%n])
				return s[(i+k)%n]<s[(j+k)%n];
		}
		return false;
	}
};

int main()
{
    Solution sol;
    sol.orderlyQueue("xmvzi",2);
    return 0;
}