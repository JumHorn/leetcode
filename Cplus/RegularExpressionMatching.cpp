#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
		int i=0;
		while(i<(int)p.length()&&p[i]=='*')//escape preceding *
			i++;
		return isMatch(s,0,p,i);
    }

	bool isMatch(const string& s,int i,const string& p,int j)
	{
		if(i>=(int)s.length()&&j>=(int)p.length())
			return true;
		if(j>=(int)p.length())
			return false;
		if(i>=(int)s.length())
		{
			if(p[j]!='*')
			{
				if(j+1>=(int)p.length()||p[j+1]!='*')
					return false;
                if(isMatch(s,i,p,j+2))
                    return true;
				j++;
			}
			while(j<(int)p.length()&&p[j]=='*')
				j++;
            return isMatch(s,i,p,j);
		}
		if(p[j]=='.')
        {
            if(j+1<(int)p.length()&&p[j+1]=='*')
                if(isMatch(s,i,p,j+2))
                    return true;
			return isMatch(s,i+1,p,j+1);
        }
		if(p[j]=='*')
		{
			char preceding=p[j-1];
			while(j<(int)p.length()&&p[j]=='*')//skip continous *
				j++;
            if(isMatch(s,i,p,j))
				return true;
			for(int k=i;k<(int)s.length();k++)
			{
                if(preceding!=s[k]&&preceding!='.')
					break;
				if(isMatch(s,k+1,p,j))
					return true;
			}
			return false;
		}
		if(s[i]!=p[j])
		{
			if(j+1<(int)p.length()&&p[j+1]=='*')
				return isMatch(s,i,p,j+2);
			return false;
		}
        if(j+1<(int)p.length()&&p[j+1]=='*')
            if(isMatch(s,i,p,j+2))
                return true;
		return isMatch(s,i+1,p,j+1);
	}
};
