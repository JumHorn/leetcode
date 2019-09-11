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
            int left=1,right=1;
            while(i-left>=0&&S[i]!=S[i-left])
                left++;
            while(i+right<(int)S.length()&&S[i]!=S[i+right])
                right++;
            res=(res+left*right)%MOD;
        }
		return res;
    }
};