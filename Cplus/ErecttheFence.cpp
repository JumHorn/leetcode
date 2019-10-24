#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
		if(points.size()<=3)
			return points;
        int leftmost=INT_MAX,index,origin;
		set<vector<int>> res;
		for(int i=0;i<(int)points.size();i++)
		{
			if(points[i][0]<leftmost)
			{
				origin=i;
				leftmost=points[i][0];
			}
		}
		index=origin;
		do
		{
			int newindex=0,cross=0;
			res.insert(points[index]);
            newindex=(index+1)%points.size();
			for(int i=0;i<(int)points.size();i++)
			{
                int tmp=crossProduct(points[index],points[i],points[newindex]);
                if(tmp>0)
                {
                    newindex=i;
                }
            }
            for(int i=0;i<(int)points.size();i++)
            {
				if(i!=index&&i!=newindex)
				{
					int tmp=crossProduct(points[index],points[i],points[newindex]);
					if(tmp==0)
					{
						if(between(points[index],points[i],points[newindex]))
						{
							res.insert(points[i]);
						}
					}
				}
			}
			index=newindex;
		}
		while(index!=origin);
		return vector<vector<int>>(res.begin(),res.end());
    }
	
	bool between(vector<int>& A,vector<int>& B,vector<int>& C)
	{
		return ((B[0]>=A[0]&&B[0]<=C[0])||(B[0]<=A[0]&&B[0]>=C[0]))
			 &&((B[1]>=A[1]&&B[1]<=C[1])||(B[1]<=A[1]&&B[1]>=C[1]));
	}

	int crossProduct(vector<int>& A,vector<int>& B,vector<int>& C)
	{
		int x1=B[0]-A[0];
		int y1=B[1]-A[1];
		int x2=C[0]-A[0];
		int y2=C[1]-A[1];
		return x1*y2-x2*y1;
	}
};