#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
		int i=0,j=s.length();        
		while(--j>=0)
			if(isPalindrome(s,i,j))
			{
				string tmp=s.substr(j+1);
				reverse(tmp.begin(),tmp.end());
				return tmp+s;
			}
		return "";
    }

	bool isPalindrome(const string& s,int i,int j)
	{
		if(i>=j)
			return true;
		while(i<j)
			if(s[i++]!=s[j--])
				return false;
		return true;
	}
};
