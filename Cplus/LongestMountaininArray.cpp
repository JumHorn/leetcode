#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {
		int index=1,left,res=0,mid;
		while(index<(int)A.size())
		{
			while(index<(int)A.size()&&A[index]<=A[index-1])
				index++;
			if(index==(int)A.size())
				break;
			left=index-1;
			while(index<(int)A.size()&&A[index]>A[index-1])
				index++;
			if(index<(int)A.size()&&A[index]==A[index-1])
				continue;
            mid=index-1;
			while(index<(int)A.size()&&A[index]<A[index-1])
				index++;
			if(index<=(int)A.size()&&mid!=index-1)
				res=max(res,index-left);
		}
		return res;
    }
};
