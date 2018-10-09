#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
		int res=0;
		for(vector<string>::iterator iter=words.begin();iter!=words.end();iter++)
		{
			for(vector<string>::iterator it=iter+1;it!=words.end();it++)
			{
				if(diff(*iter,*it))
				{
					int tmp=iter->length()*it->length();
					res=res>tmp?res:tmp;
				}
			}
		}
		return res;
    }

	bool diff(const string& s1,const string& s2) const
	{
		char hasharray[26]={0};
		for(string::const_iterator iter=s1.begin();iter!=s1.end();iter++)
		{
			hasharray[*iter-'a']=1;
		}
		for(string::const_iterator iter=s2.begin();iter!=s2.end();iter++)
		{
			if(hasharray[*iter-'a']==1)
			{
				return false;
			}
		}
		return true;
	}
};
