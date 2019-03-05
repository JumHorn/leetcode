#include<vector>
#include<string>
using namespace std;

class Solution {
	string lexicographic;
public:
    vector<vector<int> > largeGroupPositions(string S) {
		lexicographic=S;
        vector<vector<int> > res;
		vector<int> tmp(2);
		int i=0;
		while(i<(int)S.length())
		{
			int j=i+1;
			while(j<(int)S.length()&&S[i]==S[j])
				j++;
			if(j-i>=3)
			{
				tmp[0]=i;
				tmp[1]=j-1;
				res.push_back(tmp);
			}
			i=j;
		}
		sort(res.begin(),res.end(),*this);
		return res;
    }

	bool operator()(vector<int>& v1,vector<int>& v2)
	{
		return lexicographic[v1[0]]<lexicographic[v2[0]];
	}
};
