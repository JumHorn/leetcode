#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        backspace(S);
		backspace(T);
		int i=0,j=0;
		while(i<(int)S.length()&&j<(int)T.length())
		{
			while(i<(int)S.length()&&(S[i]=='#'||S[i]=='*'))i++;
			while(j<(int)T.length()&&(T[j]=='#'||T[j]=='*'))j++;
            if(i>=(int)S.length()||j>=(int)T.length())
                break;
			if(S[i]!=T[j])
				return false;
			i++;
			j++;
		}
		if(i!=(int)S.length()||j!=(int)T.length())
			return false;
		return true;
    }

	void backspace(string& s)
	{
		int index=0;
		while(index<(int)s.length())
		{
			int del=0;
			if(s[index]=='#')
			{
				del=index+1;
				while(del<(int)s.length()&&s[del]=='#')
					del++;
                int all=del-index;
				for(int i=index-1;i>=0;i--)
				{
                    if(s[i]=='#'||s[i]=='*')
                        continue;
					s[i]='*';
                    if(--all==0)
                        break;
				}
				index=del+1;
			}
			else
				++index;
		}
	}
};
