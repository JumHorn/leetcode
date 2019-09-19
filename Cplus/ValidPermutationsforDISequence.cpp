#include<string>
#include<vector>
using namespace std;

class Solution {
    static const int MOD = 1e9;
public:
    int numPermsDISequence(string S) {
		int n=S.length(),res=0;
		vector<bool> visited(n+1,false);
		vector<int> p(n+1);
		for(int i=0;i<=n;i++)
		{
			visited[i]=true;
			p[0]=i;
			res=(res+count(p,1,S,visited))%MOD;
			visited[i]=false;
		}
		return res;
    }

	int count(vector<int>& permutation,int index,const string& s,vector<bool>& visited)
	{
		int n=permutation.size();
		if(index==n)
			return 1;
		int res=0;
		if(s[index-1]=='D')
		{
			for(int i=0;i<n;i++)
			{
				if(!visited[i]&&i<permutation[index-1])
				{
					visited[i]=true;
					permutation[index]=i;
					res=(res+count(permutation,index+1,s,visited))%MOD;
					visited[i]=false;
				}
			}
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				if(!visited[i]&&i>permutation[index-1])
				{
					visited[i]=true;
					permutation[index]=i;
					res=(res+count(permutation,index+1,s,visited))%MOD;
					visited[i]=false;
				}
			}
		}
		return res;
	}
};

int main()
{
    Solution sol;
    sol.numPermsDISequence("DID");
    return 0;
}