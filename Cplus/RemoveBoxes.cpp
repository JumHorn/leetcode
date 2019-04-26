#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int removeBoxes(vector<int>& boxes)
	{
		int visited[100][100][100]={{{0}}};
		return removeBoxes(boxes,visited,0,boxes.size()-1,0);
	}

    int removeBoxes(vector<int>& boxes,int (*visited)[100][100],int l,int r,int k)
	{
		if(l>r)
			return 0;
		if(visited[l][r][k]!=0)
			return visited[l][r][k];
        while(l<r&&boxes[l]==boxes[l+1])
        {
            l++;
            k++;
        }
		int res=(k+1)*(k+1)+removeBoxes(boxes,visited,l+1,r,0);
		for(int j=l+1;j<=r;j++)
		{
			if(boxes[l]==boxes[j])
			{
				res=max(res,removeBoxes(boxes,visited,l+1,j-1,0)+removeBoxes(boxes,visited,j,r,k+1));
			}
		}
		visited[l][r][k]=res;
		return res;
    }
};
