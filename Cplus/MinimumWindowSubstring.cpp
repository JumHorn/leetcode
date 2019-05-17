#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
		unordered_map<char,int> charmap;
		int i=0,j=-1,res=INT_MAX,m=0,n=0,c=t.length();
	    for(int k=0;k<(int)t.length();k++)
			++charmap[t[k]];
		while(++j<(int)s.length())
		{
			if(charmap[s[j]]-->0)
			{
				if(--c==0)
				{
					if(res>j-i+1)
					{
						res=j-i+1;
						m=i;
						n=j;
					}
					while(i<=j)
					{
						if(++charmap[s[i]]>0)
						{
							c++;
                            i++;
							break;
						}
                        i++;
                        if(res>j-i+1)
                        {
                            res=j-i+1;
                            m=i;
                            n=j;
                        }
					}
				}
			}
		}
		if(res==INT_MAX)
			return "";
		return s.substr(m,n-m+1);
    }
};
