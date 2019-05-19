#include<string>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		if(s1.size()+s2.size()!=s3.size())
			return false;
		return isInterleave(s1,0,s2,0,s3,0);        
    }

	bool isInterleave(const string& s1,int i,const string& s2,int j,const string& s3,int k)
	{
		if(i==(int)s1.size()&&j==(int)s2.size()&&k==(int)s3.size())
			return true;
		if(i<(int)s1.size()&&s1[i]==s3[k])
			if(isInterleave(s1,i+1,s2,j,s3,k+1))
				return true;
		if(j<(int)s2.size()&&s2[j]==s3[k])
			if(isInterleave(s1,i,s2,j+1,s3,k+1))
				return true;
		return false;
	}
};
