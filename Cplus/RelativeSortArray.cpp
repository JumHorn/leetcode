#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		unordered_map<int,int> arr2indexmap;        
		int len2=arr2.size();
		for(int i=0;i<len2;i++)
			arr2indexmap[arr2[i]]=0;
		int j=arr1.size()-1;
		for(int i=arr1.size()-1;i>=0;i--)
		{
			if(arr2indexmap.find(arr1[i])==arr2indexmap.end())
				arr1[j--]=arr1[i];
			else
				arr2indexmap[arr1[i]]++;
		}
		sort(arr1.begin()+j+1,arr1.end());
		j=0;
		for(int i=0;i<len2;i++)
		{
			int s=arr2indexmap[arr2[i]];
			while(--s>=0)
				arr1[j++]=arr2[i];
		}
		return arr1;
    }
};
