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
		partition(res,s,tmp,0);
		return res;
    }

	void partition(vector<vector<string> >& res,const string& s,vector<string> tmp,int start)
	{
        if(start==s.length())
            res.push_back(tmp);
		for(int i=start+1;i<=(int)s.length();i++)
		{
            if(!isPalindromic(s,start,i))
			    continue;
            tmp.push_back(s.substr(start,i-start));
			partition(res,s,tmp,i);
            tmp.pop_back();
		}
	}

	bool isPalindromic(const string& s,int start,int end)
	{
        --end;
		while(start<end)
			if(s[start++]!=s[end--])
				return false;
		return true;
	}
};
