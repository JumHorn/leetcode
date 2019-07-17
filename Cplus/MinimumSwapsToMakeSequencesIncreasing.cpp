#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
		int res=minSwap(A,B,1);
		if(A[0]!=B[0])
		{
			swap(A[0],B[0]);
			res=min(res,minSwap(A,B,1)+1);	
		}
		return res;        
    }

	int minSwap(vector<int>& A,vector<int>& B,int index)
	{
		if(index>=(int)A.size())
			return 0;
		int res=INT_MAX;
		if(A[index]==B[index])
			return minSwap(A,B,index+1);
		bool flag=true;
		if(A[index]>A[index-1]&&B[index]>B[index-1])
		{
			flag=false;
			res=min(res,minSwap(A,B,index+1));
		}
		if(A[index]>B[index-1]&&B[index]>A[index-1])
		{
			flag=false;
			swap(A[index],B[index]);
			res=min(res,minSwap(A,B,index+1)+1);
            swap(A[index],B[index]);
		}
		if(flag)
			return 10000;
		return res;
	}
};
