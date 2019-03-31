#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res=0;
		for(int i=0;i<(int)arr.size();i++)
		{
			res++;
			int right=getIndex(arr,i);
            int rightvalue=arr[i];
			if(right<=i)
			{
				continue;
			}
			for(int j=i+1;j<=right;j++)
			{
				int tmp=getIndex(arr,j);
				if(tmp>right)
                {
					right=tmp;
                    rightvalue=arr[j];
                }
                else if(arr[j]==rightvalue)
                    right++;
				if(right==(int)arr.size())
					return res;
			}
			i=right;
		}
		return res;
    }

	int getIndex(vector<int>& arr,int start)
	{
		int res=0;
		for(int i=0;i<(int)arr.size();i++)
			if(arr[start]>arr[i])
				res++;
		return res;
	}
};
