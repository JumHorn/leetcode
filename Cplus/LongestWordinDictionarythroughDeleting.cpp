#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
		string res;
		vector<int> hash(26);
		for(int i=0;i<s.length();i++)
			hash[s[i]-'a']++;
		sort(d.begin(),d.end(),*this);
		for(int i=0;i<d.size();i++)
		{
			vector<int> tmp(26);
			for(int j=0;j<d[i].length();j++)
				tmp[d[i][j]-'a']++;
			int k;
			for(k=0;k<tmp.size();k++)
				if(tmp[k]>hash[k])
					break;
			if(k==tmp.size())
				return d[i];
		}
		return res;
    }

	bool operator()(const string& s1,const string& s2)
	{
		if(s1.length()>s2.length())
			return true;
        else if(s1.length()<s2.length())
            return false;

		if(s1<s2)
			return true;
		return false;
	}
};
