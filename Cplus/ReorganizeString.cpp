#include<string>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        map<char,int> m;
		for(string::size_type i=0;i<S.length();i++)
			m[S[i]]++;
		int max=-1;
		map<char,int>::iterator it;
		for(map<char,int>::iterator iter=m.begin();iter!=m.end();iter++)
			if(iter->second>max)
			{
				max=iter->second;
				it=iter;
			}
		if(S.length()-max<max-1)
			return "";
		char tmp=it->first;
		for(int i=0;i<S.length()-1;i++)
		{
			if(S[i]==S[i+1])
			{
				for(int j=i+2;j<S.length();j++)
				{
					if(S[i]!=S[j])
					{
						swap(S[i+1],S[j]);
						break;
					}
				}
			}
		}
        for(int i=S.length()-1;i>=1;i--)
		{
			if(S[i]==S[i-1])
			{
				for(int j=i-2;j>=0;j--)
				{
					if(S[i]!=S[j])
					{
						swap(S[i-1],S[j]);
						break;
					}
				}
			}
		}
		return S;
    }
};
