#include<vector>
#include<string>
using namespace std;

class Solution {
    vector<vector<string> > res;
public:
    vector<vector<string> > solveNQueens(int n) {
        res.clear();
		vector<int> backtracking(n);
		solveNQueens(backtracking,0,0,n);
		return res;
    }

	void solveNQueens(vector<int>& backtracking,int i,int j,int n)
	{
		while(!(i==0&&j==n))
		{
			backtracking[i]=j;
			bool flag=false;
			if(j==n)
			{
				i--;
				j=backtracking[i]+1;
				continue;
			}
			//vetical check
			flag=false;
			for(int k=0;k<i;k++)
				if(backtracking[k]==j)
				{
					j++;
					flag=true;
					break;
				}
			if(flag)
				continue;
			//slant check
			int t=i>j?j:i;
			flag=false;
			for(int k=0;k<t;k++)
				if(backtracking[i-k-1]==j-k-1)
				{
					j++;
					flag=true;
					break;
				}
			if(flag)
				continue;
			flag=false;
			t=i>n-j-1?n-1-j:i;
			for(int k=0;k<t;k++)
				if(backtracking[i-k-1]==j+k+1)
				{
					j++;
					flag=true;
					break;
				}
			if(flag)
				continue;
			
			//success or not
			if(i==n-1)
			{
				vector<string> tmp(n,string(n,'.'));
				for(int k=0;k<n;k++)
					tmp[k][backtracking[k]]='Q';
				res.push_back(tmp);
    	        if(i-1>=0)
				{
					i--;
					j=backtracking[i]+1;
					continue;
				}
                break;
			}
			else
			{
				i++;
                j=0;
				continue;
			}
		}
	}
};

int main()
{
	Solution sol;
	sol.solveNQueens(2);
}