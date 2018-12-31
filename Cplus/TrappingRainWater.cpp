#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		if(height.empty())
			return 0;
		vector<int> peek;
		peek.push_back(0);
		for(int i=1;i<(int)height.size()-1;)
        {
            int j=i+1;
            while(j+1<(int)height.size()&&height[j]==height[i])
                j++;
			if((height[i-1]-height[i])*(height[i]-height[j])<0)
				peek.push_back(i);
            i=j;
        }
		peek.push_back(height.size()-1);
		if(peek.size()<=2)
			return 0;
		int index=1;
		if(height[peek[1]]>height[0])
        {
            if(peek.size()==3)
                return 0;
			index=2;
        }
		int res=0;
		for(;index<(int)peek.size()-1;index+=2)
		{
			int low=min(height[peek[index-1]],height[peek[index+1]]);
			res+=low*(peek[index+1]-peek[index-1]-1)-sum(height,peek[index-1]+1,peek[index+1],low);
		}
        res+=trap(height);
		return res;
    }

	int sum(vector<int>& height,int i,int j,int low)
	{
		int res=0;
		for(int k=i;k<j;k++)
        {
			res+=min(height[k],low);
            height[k]=low;
        }
		return res;
	}
};
