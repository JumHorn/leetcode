#include<string>
#include<set>
using namespace std;

class Solution {
public:
    int calculate(string s) {
		int res=0,pre=0,index=0,i=0;        
		set<char> symbol={'+','-','*','/'};
		while(++i<(int)s.length())
		{
			if(symbol.find(s[i])!=symbol.end())
			{
				pre=res=stoi(s.substr(index,i-index));
				break;
			}
		}
		while(i<(int)s.length())
		{
			if(s[i]=='+')
			{
				int j=i+1;
				while(j<(int)s.length()&&symbol.find(s[j])==symbol.end())
					j++;
				pre=stoi(s.substr(i+1,j-i-1));
				res+=pre;
				pre=-pre;
				i=j;
			}
			else if(s[i]=='-')
			{
				int j=i+1;
				while(j<(int)s.length()&&symbol.find(s[j])==symbol.end())
					j++;
				pre=stoi(s.substr(i+1,j-i-1));
				res-=pre;
				pre=-pre;
				i=j;
			}
			else if(s[i]=='*')
			{
				int j=i+1;
				while(j<(int)s.length()&&symbol.find(s[j])==symbol.end())
					j++;
				res+=pre;
				pre=(-pre)*stoi(s.substr(i+1,j-i-1));
				res+=pre;
				pre-=pre;
				i=j;
			}
			else if(s[i]=='/')
			{
				int j=i+1;
				while(j<(int)s.length()&&symbol.find(s[j])==symbol.end())
					j++;
				res+=pre;
				pre=(-pre)/stoi(s.substr(i+1,j-i-1));
				res+=pre;
				pre-=pre;
				i=j;
			}
			else
				i++;
		}
		return res;
    }
};

int main()
{
    Solution sol;
    sol.calculate(" 3/2 ");
    return 0;
}