#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<string> > accountsMerge(vector<vector<string> >& accounts) {
		if(accounts.empty())
			return accounts;
		vector<pair<string,set<string> > > v;
		set<string> tmp;
		createNewAccount(accounts[0],tmp);
		v.push_back(pair<string,set<string> >(accounts[0][0],tmp));
		for(int i=1;i<(int)accounts.size();i++)
		{
			int j=0;
			for(;j<(int)v.size();j++)
			{
				if(accounts[i][0]==v[j].first)
				{
					//if the two account can be merged,merge directly,then break
					//if the two account can not be merged,continue to find if the same name still exist 
					if(canBeMerged(accounts[i],v[j].second))
					{
						for(int k=1;k<(int)accounts[i].size();k++)
						{
							v[j].second.insert(accounts[i][k]);
						}
						for(int n=j+1;n<(int)v.size();n++)
						{
							if(v[j].first==v[n].first)
							{
								if(canBeMerged(v[j].second,v[n].second))
								{
									for(set<string>::iterator iter=v[n].second.begin();iter!=v[n].second.end();++iter)
										v[j].second.insert(*iter);
									v.erase(v.begin()+n);
									//n--;
								}
							}
						}
						break;
					}
				}
			}
			//this account can not be merged insert the new account to v
			if(j==(int)v.size())
			{
				tmp.clear();
				createNewAccount(accounts[i],tmp);
				v.push_back(pair<string,set<string> >(accounts[i][0],tmp));
			}
		}			
		//convert result
		vector<vector<string> > res;
		for(int i=0;i<(int)v.size();i++)
		{
			vector<string> vtmp;
			vtmp.push_back(v[i].first);
			for(set<string>::iterator iter=v[i].second.begin();iter!=v[i].second.end();++iter)
			{
				vtmp.push_back(*iter);
			}
			res.push_back(vtmp);
		}
		return res;
    }
	
	bool canBeMerged(set<string>& src,set<string>& tmp)
	{
		for(set<string>::iterator iter=tmp.begin();iter!=tmp.end();++iter)
			if(src.find(*iter)!=tmp.end())
				return true;
		return false;
	}

	bool canBeMerged(vector<string>& account,set<string>& tmp)
	{
		for(int i=1;i<(int)account.size();i++)
			if(tmp.find(account[i])!=tmp.end())
				return true;
		return false;
	}

	void createNewAccount(vector<string>& account,set<string>& tmp)
	{
		for(int i=1;i<(int)account.size();i++)
			tmp.insert(account[i]);
	}
};
