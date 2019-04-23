#include<vector>
#include<set>
#include<iostream>
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
            int area=0;
            int nextheight=INT_MAX;
			for(int i=0;i<(int)heightMap.size();i++)
				for(int j=0;j<(int)heightMap[0].size();j++)
				{
                    if(heightMap[i][j]==-1)
                        continue;
                    if(heightMap[i][j]>height)
                    {
                        nextheight=min(nextheight,heightMap[i][j]);
                        flag=true;
                        continue;
                    }
					int tmp=trapRainWater(heightMap,visited,i,j,height);
					if(tmp>=0)
					{
						for(set<pair<int,int> >::iterator iter=visited.begin();iter!=visited.end();++iter)
							heightMap[iter->first][iter->second]=height+1;
						area+=tmp;
					}
					else
					{
						//fill all the hole
						for(set<pair<int,int> >::iterator iter=visited.begin();iter!=visited.end();++iter)
							heightMap[iter->first][iter->second]=-1;
					}
					visited.clear();
				}
            res+=(nextheight-height)*area;
            height=nextheight;
		}
		return res;
    }

	int trapRainWater(vector<vector<int> >& heightMap,set<pair<int,int> >& visited,int i,int j,int h)
	{
		if(heightMap[i][j]==-1)
			return -1;
		if(visited.find(pair<int,int>(i,j))!=visited.end())
			return 0;
		if(heightMap[i][j]>h)
			return 0;
		if(i==0||i==(int)heightMap.size()-1||j==0||j==(int)heightMap[0].size()-1)
			return -1;
		visited.insert(pair<int,int>(i,j));
		int res=1;
		int direction[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
		for(int k=0;k<4;k++)
		{
			int x=i+direction[k][0],y=j+direction[k][1];
			int tmp=trapRainWater(heightMap,visited,x,y,h);
			if(tmp<0)
				return -1;
			res+=tmp;
		}
		return res;
	}
};

int main()
{
	int a[][3]={{11,21,31},{81,9,4},{17,61,51}};
	vector<vector<int> > rain;
	for(int i=0;i<6;i++)
	{
		vector<int> tmp(a[i],a[i]+6);
		rain.push_back(tmp);
	}
	Solution sol;
	int n=sol.trapRainWater(rain);
	cout<<n<<endl;
	return 0;
}