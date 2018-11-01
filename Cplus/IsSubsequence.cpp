#include<string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
		if(s.empty())
			return true;
		int i=0,j=0;
		for(i=0;i<t.length();i++)
		{
			if(s[j]==t[i])
			{
				j++;
				if(j==s.length())
				{
					break;
				}
			}
		}		
		return i!=t.length();
    }
};
