#include<string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
		int hash['z'-'A'+1]={0};
		for(int i=0;i<(int)S.length();i++)
			hash[S[i]-'A']++;
		int res=0;
		for(int j=0;j<(int)J.length();j++)
			res+=hash[J[j]-'A'];
		return res;		
    }
};
