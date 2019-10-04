#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
	    auto iter=max_element(s.begin(),s.end()); 
		int res=distance(s.begin(),iter);
		for(int i=res+1;i<(int)s.length();i++)
			if(s[i]==*iter)
			{
				int j=res,k=i;
				while(i<(int)s.length()&&s[++i]==s[++j]);
				if(i==(int)s.length())
					break;
				if(s[i]>s[j])
                {
					res=k;
                    i=k;
                }
                else
				    i--;
			}
		return s.substr(res);
    }
};
