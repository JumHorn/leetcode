#include<string>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
		set<string> s;
		string local,domain;
		for(int i=0;i<(int)emails.size();i++)
		{
			for(int j=0;j<(int)emails[i].size();j++)
			{
				if(emails[i][j]=='.')
				{
					emails[i].erase(emails[i].begin()+j);
					j--;
				}
				else if(emails[i][j]=='+'||emails[i][j]=='@')
				{
					local=emails[i].substr(0,j);
					while(emails[i][j]!='@')
						j++;
					domain=emails[i].substr(j+1,emails[i].size()-j-1);
					s.insert(local+"@"+domain);
                    break;
				}
			}
		}
		return s.size();
    }
};
