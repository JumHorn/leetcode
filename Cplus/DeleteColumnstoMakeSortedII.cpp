#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		stack<pair<int,int>> index;
		int M=A.size(),N=A[0].length(),res=0;
        bool flag=true;
		for(int i=0;i<N;i++)
		{
			if(flag)
			{
				int j=0;
				for(j=0;j<M-1;j++)
					if(A[j][i]>A[j+1][i])
						break;
				if(j==M-1)
                {
                    flag=false;
                    for(j=0;j<M-1;j++)
                        if(A[j][i]==A[j+1][i])
                            index.push({j,j+1});
                }
                else
                    res++;
			}
			else
			{
                if(index.empty())
                    return res;
                stack<pair<int,int>> s=index,tmp;
                while (!s.empty())
                {
                    if(A[s.top().first][i]>A[s.top().second][i])
                    {
                        res++;
                        break;
                    }
                    else if(A[s.top().first][i]==A[s.top().second][i])
                        tmp.push(s.top());
                    s.pop();
                }
                if(s.empty())
                    index=tmp;
			}
		}
		return res;
	}
};