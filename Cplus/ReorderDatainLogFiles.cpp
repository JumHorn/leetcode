#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitlog,letterlog;
		for(int i=0;i<(int)logs.size();i++)
		{
			int j=0;
			while(logs[i][j]!=' ')
				j++;
			if(isdigit((logs[i][j+1])))
				digitlog.push_back(logs[i]);
			else
				letterlog.push_back(logs[i]);
		}
		sort(letterlog.begin(),letterlog.end(),*this);
		for(int i=0;i<(int)digitlog.size();i++)
			letterlog.push_back(digitlog[i]);
		return letterlog;
    }

	bool operator()(const string& lhs,const string& rhs)
	{
		int i=0,j=0;
		while(lhs[i]!=' ')
			i++;
		while(rhs[j]!=' ')
			j++;
		if(lhs.substr(i)!=rhs.substr(j))
			return lhs.substr(i)<rhs.substr(j);
		return lhs.substr(0,i)<rhs.substr(0,j);
	}
};
