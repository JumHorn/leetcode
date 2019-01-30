#include<string>
using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
		if(A.size()!=B.size())
			return false;
		char a[2],b[2];
		int num=0;
		for(int i=0;i<(int)A.size();i++)
		{
			if(A[i]!=B[i])
			{
				if(num==2)
					return false;
				else
				{
					a[num]=A[i];
					b[num]=B[i];
					num++;
				}
			}
		}	
		if(num==0)
		{
			int hash[26]={0};
			for(int i=0;i<(int)A.size();i++)
			{
				if(++hash[A[i]-'a']==2)
					return true;
			}
			return false;
		}
		return a[0]==b[1]&&a[1]==b[0];	
    }
};
