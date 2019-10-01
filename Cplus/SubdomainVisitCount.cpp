#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
		unordered_map<string,int> domainmap;
	    for(int i=0;i<(int)cpdomains.size();i++)
		{
			int j=0,c=0;
			while(cpdomains[i][j]!=' ')
				j++;
			c=stoi(cpdomains[i].substr(0,j));
			domainmap[cpdomains[i].substr(++j)]+=c;;
			while(cpdomains[i][j]!='.')
				j++;
			domainmap[cpdomains[i].substr(++j)]+=c;
			while(j<(int)cpdomains[i].size()&&cpdomains[i][j]!='.')
				j++;
			if(j!=(int)cpdomains[i].size())
				domainmap[cpdomains[i].substr(j+1)]+=c;
		}	
		vector<string> res;
		for(auto& n : domainmap)
			res.push_back(to_string(n.second)+" "+n.first);
		return res;
    }
};
