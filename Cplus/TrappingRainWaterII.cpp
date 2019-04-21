#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int> >& heightMap) {
        int height=-1,res=0;
		if(heightMap.size()<3)
			return 0;
		set<pair<int,int> > visited;
		bool flag=true;
		while(flag)
		{
			flag=false;
			height++;
			for(int i=1;i<(int)heightMap.size()-1;i++)
				for(int j=1;j<(int)heightMap[0].size()-1;j++)
				{
					int tmp=trapRainWater(heightMap,visited,i,j,height,flag);
					if(tmp>=0)
					{
						for(set<pair<int,int> >::iterator iter=visited.begin();iter!=visited.end();++iter)
							heightMap[iter->first][iter->second]=height+1;
						res+=tmp;
					}
					else
					{
						//fill all the hole
						for(set<pair<int,int> >::iterator iter=visited.begin();iter!=visited.end();++iter)
							heightMap[iter->first][iter->second]=-1;
					}
					visited.clear();
				}
		}
		return res;
    }

	int trapRainWater(vector<vector<int> >& heightMap,set<pair<int,int> >& visited,int i,int j,int h,bool& f)
	{
		if(heightMap[i][j]==-1)
			return -1;
		if(visited.find(pair<int,int>(i,j))!=visited.end())
			return 0;
		if(heightMap[i][j]>h)
		{
			f=true;
			return 0;
		}
		if(i==0||i==(int)heightMap.size()-1||j==0||j==(int)heightMap[0].size())
			return -1;
		visited.insert(pair<int,int>(i,j));
		int res=1;
		int direction[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
		for(int k=0;k<4;k++)
		{
			int x=i+direction[k][0],y=j+direction[k][1];
			int tmp=trapRainWater(heightMap,visited,x,y,h,f);
			if(tmp<0)
				return -1;
			res+=tmp;
		}
		return res;
	}
};

int main()
{
	int a[]={1,0,1};
	vector<int> tmp(a,a+3);
	vector<vector<int> > rain;
	rain.push_back(tmp);
	rain.push_back(tmp);
	rain.push_back(tmp);
	rain[1][1]=0;
	Solution sol;
	sol.trapRainWater(rain);
	return 0;
}