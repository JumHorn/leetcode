#include<string>
#include<vector>
using namespace std;

class Solution {
	static const int MOD = 1e9+7;
public:
    int uniqueLetterString(string S) {
		int res=0;
		for(int i=0;i<(int)S.length();i++)
        {
            vector<int> v(26);
            int unique=0;            
			for(int j=i;j<(int)S.length();j++)
			{
				if(++v[S[j]-'A']==1)
					unique++;
				if(v[S[j]-'A']==2)
					unique--;
				res=(res+unique)%MOD;
			}
        }
		return res;
    }
};