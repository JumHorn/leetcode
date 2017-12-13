#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> *grid;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = &grid;
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int temp = areasum(i,j);
                ans = temp>ans?temp:ans;
            }
        }
        return ans;
    }

    int areasum(int r,int c)
    {
        if(r<0||r>=(*grid).size()||c<0||c>=(*grid)[0].size()||(*grid)[r][c]==0)
        {
            return 0;
        }
        (*grid)[r][c]=0;
        return (1+areasum(r+1,c)+areasum(r-1,c)+areasum(r,c-1)+areasum(r,c+1));
    }
};

//memory limit exceeded
// class Solution0 {
// public:
//     vector<vector<int> > groups;
//     vector<int> num;
//     int AreasumOfIsland(vector<vector<int>>& grid) {
//         vector<int> temp;
//         for(int i=0,j=0;i<grid[0].size();i++)
//         {
//             if(grid[0][i]==1)
//             {
//                 temp.clear();
//                 temp.push_back(i);
//                 num.push_back(1);
//                 i++;
//                 while(i<grid[0].size()&&grid[0][i]==1)
//                 {
//                     temp.push_back(i);
//                     num[j]++;
//                 }
//                 groups.push_back(temp);
//                 j++;
//             }
//         }
//         if(grid.size()==1)
//         {
//             return *max_element(num.begin(),num.end());
//         }
//         for(int i=1;i<grid.size();i++)
//         {

//         }
//     }
// };