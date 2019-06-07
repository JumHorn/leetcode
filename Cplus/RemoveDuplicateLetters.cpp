#include<string>
#include<map>
#include<set>
#include<iostream>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
		map<char,int> m;
		for(int i=0;i<(int)s.length();i++)
			++m[s[i]];	
		string res(m.size(),'\0');
		int index=0,j=0;
		set<char> visited;
		map<char,int>::iterator it=m.begin();
		for(int i=0;i<(int)s.length();i++)
		{
			if(m[s[i]]<=0)
				continue;
			if(it->first==s[i])
			{
				res[index++]=it->first;
				m[it->first]=0;
				while(it!=m.end()&&it->second==0)
					++it;
				j=i+1;
				visited.clear();
			}
			else if(m[s[i]]==1)
			{
				set<char>::iterator iter=visited.begin();
				int k=j,n=j;
				while(k<i&&iter!=visited.end()&&*iter<s[i])
				{
					while(k<i)
					{
						if(s[k]==*iter)
                        {
                            res[index++]=*iter;
						    m[*iter]=0;
						    ++iter;
							n=k+1;
							break;
                        }
						k++;
					}
					if(k==i)
						++iter;
					k=n;
				}
				bool flag=true;
				while(k<i)
				{
					if(s[k]==s[i])
					{
						flag=false;
						visited.clear();
						res[index++]=s[i];
						int tmp=i;
						m[s[tmp]]=0;
						i=k;
						while (++k<tmp)
							if(m[s[k]]!=0)
								++m[s[k]];
						j=i+1;
					}
					k++;
				}
				if(flag)
				{
					visited.clear();
					res[index++]=s[i];
					m[s[i]]=0;
					j=i+1;
				}
			}
			else
			{
				visited.insert(s[i]);
				--m[s[i]];
			}
		}
		return res;
    }
};
