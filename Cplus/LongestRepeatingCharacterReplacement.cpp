#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
		int window=0,maxcount=0;
		vector<int> hash(26,0);
		for(int j=0;j<s.length();j++)
		{
			hash[s[j]-'A']++;
			maxcount=max(hash[s[j]-'A'],maxcount);//this trick makes the algorithm the best
			window-maxcount<k?window++:hash[s[j-window]-'A']--;
		}
		return window;
    }
};
