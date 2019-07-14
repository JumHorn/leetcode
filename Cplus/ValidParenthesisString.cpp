#include<string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
		int low=0,high=0;//the number of left bracket in range [low,high]
		for(int i=0;i<(int)s.length();i++)
		{
            if(s[i]=='(')
                low++;
            else if(low>0)
                low--;

            if(s[i]!=')')
                high++;
            else
                high--;
            if(high<0)
                return false;
		}
        return low==0;
    }
};