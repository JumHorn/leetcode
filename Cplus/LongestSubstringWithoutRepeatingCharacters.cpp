#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> m;
		int res=0;
		for(int i=0,j=0;i<(int)s.length();i++)
		{
			if(m.find(s[i])==m.end())
			{
				m.insert(s[i]);
				res=max(res,(int)m.size());
			}
			else
			{
				while(s[j]!=s[i])
					m.erase(s[j++]);
                j++;
			}
		}
		return res;
    }
};
