#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
		stringstream ss;
		int index=0,num=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]<'0'||s[i]>'9')
				continue;
			ss<<s.substr(index,i-index);
			for(index=i;s[index]!='[';index++)
				num=10*num+(s[index]-'0');
			int bracket=1;
			for(int j=index+1;j<s.length();j++)
			{
				if(s[j]==']')
					bracket--;
				else if(s[j]=='[')
					bracket++;
				if(bracket==0)
				{
					bracket=j;
					break;
				}
			}
			i=bracket;
			string tmp=decodeString(s.substr(index+1,bracket-index-1));
			for(int k=0;k<num;k++)
				ss<<tmp;
			num=0;
			index=bracket+1;
		}
		ss<<s.substr(index,s.length()-index);
		return ss.str();
    }
};
