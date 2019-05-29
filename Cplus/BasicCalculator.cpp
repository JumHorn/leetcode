#include<string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
		return calculate(s,0,s.length());       
    }

	int calculate(const string& s,int i,int j)
	{
		if(i>=j)
			return 0;
		int res=0,tmp=i,flag=0,n=0,newflag=0;
		while(i<j)
		{
			if(flag==0)
				res+=n;
			else
				res-=n;
			tmp=i;
			flag=newflag;
			if(s[i]=='(')
			{
				int parenthesis=1;
				while(i<j)
				{
					if(s[i]=='(')
						parenthesis++;
					else if(s[i]==')')
						parenthesis--;
					if(parenthesis==0)
						break;
					i++;
				}
				n=calculate(s,tmp+1,i-1);
				i++;
				if(i<j)
				{
					if(s[i]=='+')
						newflag=0;
					else
						newflag=1;
				}
			}
			else if(s[i]=='+')
			{
				n=stoi(s.substr(tmp,i-tmp));
				newflag=0;
			}
			else if(s[i]=='-')
			{
				n=stoi(s.substr(tmp,i-tmp));
				newflag=1;
			}
			else
				i++;
		}
		return res;
	}
};
