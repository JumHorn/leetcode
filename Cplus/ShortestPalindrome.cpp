#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//kmp next array

class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.empty())
            return "";
		string rev=s;
		reverse(rev.begin(),rev.end());
		string t=s+'#'+rev;
		vector<int> next(t.length());
		int k=0;
		for(int i=1;i<(int)next.size();i++)
		{
			if(t[next[i-1]]==t[i])
				next[i]=next[i-1]+1;
			else
			{
                k=i;
				k=next[k-1];
				while(k>0&&t[k]!=t[i])
				{
					k=next[k-1];
				}
				if(t[k]==t[i])
                    ++k;
				next[i]=k;
			}
		}
		return rev.substr(0,rev.length()-next.back())+s;
    }
};
