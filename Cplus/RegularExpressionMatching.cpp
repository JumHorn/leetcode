#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
		return isMatch(s,0,p,0);        
    }

	bool isMatch(const string& s,int i,const string& p,int j)
	{
		if(i>=(int)s.length()&&j>=(int)p.length())
			return true;
		if(j>=(int)p.length())
			return false;
		if(i>=(int)s.length())
		{
			while(j<(int)p.length()&&p[j]=='*')
				j++;
			return j==(int)p.length();
		}
		if(p[j]=='.')
			return isMatch(s,i+1,p,j+1);
		if(p[j]=='*')
		{
			while(j<(int)p.length()&&p[j]=='*')//skip continous *
				j++;
			if(j==(int)p.length())
				return true;
			for(int k=i;k<(int)s.length();k++)
			{
				if(isMatch(s,k,p,j))
					return true;
			}
			return false;
		}
		if(s[i]!=p[j])
			return false;
		return isMatch(s,i+1,p,j+1);
	}
};
