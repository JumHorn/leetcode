#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;

class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
		int M=grid.size(),N=grid[0].size(),res=0;
		vector<vector<int>> newgrid(M*2-1,vector<int>(N*2-1));        
		int tag=2;
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				if(grid[i][j]==1)
					tagArea(grid,tag++,i,j);
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				newgrid[2*i][2*j]=grid[i][j];

		map<int,int> affectedmap;
        pair<int,int> maxpair;
        do
        {
            affectedmap=getAffected(newgrid,M,N);
            if(affectedmap.empty())
                break;
            maxpair=getMaxPair(affectedmap);
            res+=maxpair.second;
            if(affectedmap.size()<=1)
                break;
            buildWalls(newgrid,M,N,maxpair.first);
            cout<<"build walls"<<endl;
            print(newgrid);
            affectedExpand(newgrid,M,N);
            cout<<"affected Expand"<<endl;
            print(newgrid);
        }while(maxpair.second!=0);
		return res;
    }

    void print(vector<vector<int>>& newgrid)
    {
        for(auto n:newgrid)
        {
            for(auto m:n)
                printf("%-3d",m);
            cout<<endl;
        }
    }

    void affectedExpand(vector<vector<int>>& newgrid,int M,int N)
    {
        set<pair<int,int>> v;
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
			{
				set<int> s;
                bool flag=false;
				if(newgrid[2*i][2*j]==0)
				{
                    if(2*i-2>=0&&newgrid[2*i-1][2*j]!=1&&newgrid[2*i-2][2*j]!=0)
                    {
                        if(v.find({2*i-2,2*j})==v.end())
                        {
                            v.insert({2*i,2*j});
                            newgrid[2*i][2*j]=newgrid[2*i-2][2*j];
                            flag=true;
                        }
                        s.insert(newgrid[2*i-2][2*j]);
                    }
                    if(2*i+2<2*M-1&&newgrid[2*i+1][2*j]!=1&&newgrid[2*i+2][2*j]!=0)
                    {
                        if(v.find({2*i+2,2*j})==v.end())
                        {
                            v.insert({2*i,2*j});
                            newgrid[2*i][2*j]=newgrid[2*i+2][2*j];
                            flag=true;
                        }
                        s.insert(newgrid[2*i+2][2*j]);
                    }
                    if(2*j-2>=0&&newgrid[2*i][2*j-1]!=1&&newgrid[2*i][2*j-2]!=0)
                    {
                        if(v.find({2*i,2*j-2})==v.end())
                        {
                            v.insert({2*i,2*j});
                            newgrid[2*i][2*j]=newgrid[2*i][2*j-2];
                            flag=true;
                        }
                        s.insert(newgrid[2*i][2*j-2]);
                    }
                    if(2*j+2<2*N-1&&newgrid[2*i][2*j+1]!=1&&newgrid[2*i][2*j+2]!=0)
                    {
                        if(v.find({2*i,2*j+2})==v.end())
                        {
                            v.insert({2*i,2*j});
                            newgrid[2*i][2*j]=newgrid[2*i][2*j+2];
                            flag=true;
                        }
                        s.insert(newgrid[2*i][2*j+2]);
                    }
                }
                if(flag&&s.size()>1)
                    reTagArea(newgrid,s,*s.begin(),M,N);
			}
    }

    void buildWalls(vector<vector<int>>& newgrid,int M,int N,int tag)
    {
        for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
			{
				if(newgrid[2*i][2*j]==0)
				{
                    if(2*i-2>=0&&newgrid[2*i-1][2*j]!=1&&newgrid[2*i-2][2*j]==tag)
                        newgrid[2*i-1][2*j]=1;
                    if(2*i+2<2*M-1&&newgrid[2*i+1][2*j]!=1&&newgrid[2*i+2][2*j]==tag)
                        newgrid[2*i+1][2*j]=1;
                    if(2*j-2>=0&&newgrid[2*i][2*j-1]!=1&&newgrid[2*i][2*j-2]==tag)
                        newgrid[2*i][2*j-1]=1;
                    if(2*j+2<2*N&&newgrid[2*i][2*j+1]!=1&&newgrid[2*i][2*j+2]==tag)
                        newgrid[2*i][2*j+1]=1;
                }
			}
    }

    pair<int,int> getMaxPair(map<int,int>& affectedmap)
    {
        return *max_element(begin(affectedmap),end(affectedmap),
        [](const pair<int,int>& lhs, const pair<int,int>& rhs){return lhs.second<rhs.second;});
    }

    map<int,int> getAffected(vector<vector<int>>& newgrid,int M,int N)
    {
        map<int,int> res;
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
			{
				set<int> s;
				if(newgrid[2*i][2*j]==0)
				{
                    if(2*i-2>=0&&newgrid[2*i-1][2*j]!=1&&newgrid[2*i-2][2*j]!=0)
                        ++res[newgrid[2*i-2][2*j]];
                    if(2*i+2<2*M-1&&newgrid[2*i+1][2*j]!=1&&newgrid[2*i+2][2*j]!=0)
                        ++res[newgrid[2*i+2][2*j]];
                    if(2*j-2>=0&&newgrid[2*i][2*j-1]!=1&&newgrid[2*i][2*j-2]!=0)
                        ++res[newgrid[2*i][2*j-2]];
                    if(2*j+2<2*N-1&&newgrid[2*i][2*j+1]!=1&&newgrid[2*i][2*j+2]!=0)
                        ++res[newgrid[2*i][2*j+2]];
                }
			}
        return res;
    }

    void reTagArea(vector<vector<int>>& newgrid,set<int>& s,int tag,int M,int N)
    {
        for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
                if(s.find(newgrid[2*i][2*j])!=s.end())
                    newgrid[2*i][2*j]=tag;
    }

	void tagArea(vector<vector<int>>& grid,int tag,int i,int j)
	{
		if(i<0||i>=(int)grid.size()||j<0||j>=(int)grid[0].size()||grid[i][j]!=1)
			return;
		grid[i][j]=tag;
		tagArea(grid,tag,i-1,j);
		tagArea(grid,tag,i+1,j);
		tagArea(grid,tag,i,j-1);
		tagArea(grid,tag,i,j+1);
	}
};

int main()
{
    vector<vector<int>> grid=
    {
        {0,1,0,1,1,1,1,1,1,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,1,1,1,0,0,0,1,0},
        {0,0,0,1,1,0,0,1,1,0},
        {0,1,0,0,1,0,1,1,0,1},
        {0,0,0,1,0,1,0,1,1,1},
        {0,1,0,0,1,0,0,1,1,0},
        {0,1,0,1,0,0,0,1,1,0},
        {0,1,1,0,0,1,1,0,0,1},
        {1,0,1,1,0,1,0,1,0,1}
    };
    Solution sol;
    sol.containVirus(grid);
    return 0;
}