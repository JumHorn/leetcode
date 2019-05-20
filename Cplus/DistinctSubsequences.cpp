#include<string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
		return numDistinct(s,0,t,0);        
    }

	int numDistinct(const string& s,int i,const string& t,int j)
	{
		if(j>=(int)t.size())
			return 1;
		int res=0;
		for(int k=i;k<(int)s.size();k++)
		{
			if(s[k]==t[j])
				res+=numDistinct(s,k+1,t,j+1);
		}
		return res;
	}
};
