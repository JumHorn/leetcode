#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
		int degree=0,x=0,y=0,res=0;        
		int dirs[][2]={{0,1},{1,0},{0,-1},{-1,0}};
		set<pair<int,int>> ob;
		for(int i=0;i<(int)obstacles.size();i++)
			ob.insert({obstacles[i][0],obstacles[i][1]});
		for(int i=0;i<(int)commands.size();i++)
		{
			if(commands[i]<0)
			{
				if(commands[i]==-1)
					degree+=1;
				else
					degree-=1;
				degree=(degree+4)%4;
			}
			else
			{
				for(int j=1;j<=commands[i];j++)
				{
					if(ob.find({x+dirs[degree][0],y+dirs[degree][1]})==ob.end())
					{
						x+=dirs[degree][0];
						y+=dirs[degree][1];
						res=max(res,x*x+y*y);
					}
					else
						break;
				}
			}
		}
		return res;
    }
};
