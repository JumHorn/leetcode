#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res=0,i=0;
		while(i<arr.size())
		{
			int tmp = i;
			for(int j=i+1;j<arr.size();j++)
			{
				if(arr[i]>arr[j])
				{
					tmp=j;
				}
			}
			int t = *max_element(arr.begin()+i,arr.begin()+tmp+1);
			i=tmp+1;
			for(int j=tmp+1;j<arr.size();j++)
			{
				if(t>arr[j])
				{
					i=j+1;
				}
			}
			res++;
		}	
		return res;
    }
};
