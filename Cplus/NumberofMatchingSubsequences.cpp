#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
		vector<vector<pair<int,int> > > index(128);
		for(int i=0;i<(int)words.size();i++)
			index[words[i][0]].push_back(pair<int,int>(i,0));
		for(int i=0;i<(int)S.size();i++)
		{
			vector<pair<int,int> > v=index[S[i]];
			index[S[i]].clear();
			for(int j=0;j<(int)v.size();j++)
			{
				index[words[v[j].first][++v[j].second]].push_back(pair<int,int>(v[j].first,v[j].second));
			}
		}
		return index[0].size();		
    }
};
