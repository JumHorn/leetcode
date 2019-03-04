#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
		vector<int> res(S.length(),INT_MAX);
		for(int i=0;i<(int)S.length();i++)
		{
			if(S[i]==C)
			{
				res[i]=0;
				for(int j=i+1;j<(int)S.length();j++)
				{
					if(res[j]>j-i)
						res[j]=j-i;
				}
				for(int j=i-1;j>=0;j--)
				{
					if(res[j]>i-j)
						res[j]=i-j;
				}
			}
		}
		return res;		
    }
};
