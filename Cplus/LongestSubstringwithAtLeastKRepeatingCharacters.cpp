#include<string>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
		return longestSubstring(s,k,0,s.length());
    }

	int longestSubstring(const string& s,int k,int left,int right)
	{
		if(left>=right)
			return 0;
		int hash[26]={0};
		for(int i=left;i<right;i++)
			hash[s[i]-'a']++;
		for(int i=left;i<right;i++)
		{
			if(hash[s[i]-'a']<k)
			{
				return max(longestSubstring(s,k,left,i),longestSubstring(s,k,i+1,right));
			}
		}
		return right-left;		
	}
};
