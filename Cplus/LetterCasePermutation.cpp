#include<vector>
#include<string>
#include<locale>
#include<cctype>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
		vector<string> res;
		letterCasePermutation(res,S,0);
		return res;		
    }

	void letterCasePermutation(vector<string>& v,string s,int start)
	{
		if(start==(int)s.length())
		{
			v.push_back(s);
			return;
		}
		if(!isalpha(s[start]))
			return letterCasePermutation(v,s,start+1);
		s[start]=tolower(s[start]);
		letterCasePermutation(v,s,start+1);
		s[start]=toupper(s[start]);
		letterCasePermutation(v,s,start+1);
	}
};
