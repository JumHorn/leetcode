#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		priority_queue<pair<int,int>> ipo,noipo;
 		for(int i=0;i<(int)Profits.size();i++)
		{
			if(Capital[i]<=W)
				ipo.push({Profits[i],Capital[i]});
			else
				noipo.push({-Capital[i],Profits[i]});
		}
		for(int i=0;i<k;i++)
		{
			if(ipo.empty())
				break;
			W+=ipo.top().first;
			ipo.pop();
			while(!noipo.empty())
			{
				if(W>=-noipo.top().first)
				{
					ipo.push({noipo.top().second,-noipo.top().first});
					noipo.pop();
				}
				else
					break;
			}
		}
		return W;
    }
};
