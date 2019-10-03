#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowel={'a','e','i','o','u','A','E','I','O','U'};
		int i=0,j=0,len=S.length();
		string res,aaa="a";
		while(i<len)
		{
			while(j<len&&S[j]!=' ')
				j++;
			if(vowel.find(S[i])!=vowel.end())
				res+=" "+S.substr(i,j-i)+"ma"+aaa;
			else
				res+=" "+S.substr(i+1,j-i-1)+S[i]+"ma"+aaa;
			i=++j;
			aaa+="a";
		}
		return res.substr(1);
    }
};
