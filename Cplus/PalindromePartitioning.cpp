#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
		if(s.empty())
			return vector<vector<string> >();
        vector<vector<string> > res;
		vector<string> tmp;
		partition(res,s,tmp,0,0);
		return res;
    }

	void partition(vector<vector<string> >& res,const string& s,vector<string>& tmp,int start,int end)
	{
		for(int i=end;i<(int)s.length();i++)
		{
			if(!isPalindromic(s,start,end))
				return;
			tmp.push_back(s.substr(start,end-start+1));
			partition(res,s,tmp,end,i);
			tmp.pop_back();
		}
		res.push_back(tmp);
	}
	
	bool isPalindromic(const string& s,int start,int end)
	{
		while(start<end)
			if(s[start++]!=s[end--])
				return false;
		return true;
	}
};
