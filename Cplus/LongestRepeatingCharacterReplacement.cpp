#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length()<=k)
            return s.length();
		int window=k,maxcount=0;
		vector<int> hash(26,0);
		for(int i=0;i<k;i++)
			hash[s[i]-'A']++;
		for(int j=k;j<s.length();j++)
		{
			hash[s[j]-'A']++;
			maxcount=max(hash[s[j]-'A'],maxcount);//this trick makes the algorithm the best
			if(window-maxcount<k)
				window++;
			else
				hash[s[j-window]-'A']--;
		}
		return window;
    }
};
