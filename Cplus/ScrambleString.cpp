#include<string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
		if(s1==s2)
			return true;
		int hashmap[26]={0};
        for(int i=0;i<(int)s1.length();i++)
        {
            ++hashmap[s1[i]-'a'];
            --hashmap[s2[i]-'a'];
        }
        for(int i=0;i<26;i++)
            if(hashmap[i]!=0)
                return false;
        int len=s1.length();
    	for(int i=1;i<len;i++)
        {
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0,i),s2.substr(len-i))&&isScramble(s1.substr(i),s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
};