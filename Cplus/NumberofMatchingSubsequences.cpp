#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
		int res=0;
		vector<int> index(words.size());
		for(int i=0;i<(int)S.size();i++)
		{
			for(int j=0;j<(int)words.size();j++)
			{
				if(index[j]==(int)words[j].size())
					continue;
				if(S[i]==words[j][index[j]])
					++index[j];
			}
		}
		for(int i=0;i<(int)words.size();i++)
			res+=((int)words[i].size()==index[i])?1:0;
		return res;		
    }
};
