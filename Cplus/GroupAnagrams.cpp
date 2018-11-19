#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
		vector<vector<string> > res;
        vector<vector<int> > hasharray;
		for(int i=0;i<strs.size();i++)
		{
			vector<int> hash(26,0);
			for(int j=0;j<strs[i].length();j++)
				hash[strs[i][j]-'a']++;
			int k;
			for(k=0;k<hasharray.size();k++)
				if(compareHashArray(hasharray[k],hash))
				{
					res[k].push_back(strs[i]);
					break;
				}
			if(k==hasharray.size())
			{
				res.push_back(vector<string>(1,strs[i]));
				hasharray.push_back(hash);
			}
		}
		return res;
    }

	bool compareHashArray(vector<int>& v1,vector<int>& v2)
	{
		for(int i=0;i<v1.size();i++)
			if(v1[i]!=v2[i])
				return false;
		return true;
	}
};
