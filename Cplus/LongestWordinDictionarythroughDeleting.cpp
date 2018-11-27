#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
		string res;
		sort(d.begin(),d.end(),*this);
		for(int i=0;i<d.size();i++)
		{
			int j=0,k=0;
			for(j=0;j<s.length();j++)
			{
				if(d[i][k]==s[j])
					k++;
				if(k==d[i].length())
					return d[i];
			}
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
