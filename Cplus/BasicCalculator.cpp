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
		int res=0,tmp=i,flag=0,newflag=0,n=0;
		while(i<j)
		{
			if(s[i]=='(')
			{
				int parenthesis=1;
				while(++i<j)
				{
					if(s[i]=='(')
						parenthesis++;
					else if(s[i]==')')
						parenthesis--;
					if(parenthesis==0)
						break;
				}
				n=calculate(s,tmp+1,i);
				while(++i<j&&s[i]==' ');
				if(i<j)
				{
					if(s[i]=='+')
						newflag=0;
					else
						newflag=1;
				}
				i++;
				tmp=i;
			}
			else if(s[i]=='+')
			{
				newflag=0;
				i++;
				tmp=i;
			}
			else if(s[i]=='-')
			{
				newflag=1;
				i++;
				tmp=i;
			}
			else
			{
				while(i<j&&s[i]!='('&&s[i]!='+'&&s[i]!='-')
					i++;
				if((i<j&&s[i]!='(')||i>=j)
					n=stoi(s.substr(tmp,i-tmp));
				else
					tmp=i+1;
				continue;
			}
			if(i<j)
			{
				if(flag==0)
					res+=n;
				else
					res-=n;
			}
			flag=newflag;
		}
		if(flag==0)
			res+=n;
		else
			res-=n;
		return res;
	}
};
