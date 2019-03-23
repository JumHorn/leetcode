#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
		vector<int> res(S.length()+1);
		int decs=S.length(),acr=0;
		for(int i=0;i<(int)S.length();i++)
		{
			if(S[i]=='I')
				res[i]=acr++;
			else
				res[i]=decs--;
		}		
		res.back()=acr;
		return res;
    }
};
