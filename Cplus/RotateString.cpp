#include<string>
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
		if(A==B)
			return true;
		if(A.length()!=B.length())
			return false;
		for(int i=0;i<(int)A.length();i++)
		{
			int len=A.length();
			if(A.substr(i)==B.substr(0,len-i)&&A.substr(0,i)==B.substr(len-i))
				return true;
		}
		return false;		
    }
};
