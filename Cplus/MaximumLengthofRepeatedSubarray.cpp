#include<vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
		int res=0;
		A.push_back(101);
		B.push_back(102);
		for(int i=0;i<A.size()-1;i++)
		{
			int tmp=i;
			for(int j=0;j<B.size()-1;j++)
			{
				int len=0,n=j;
                tmp=i;
				while(A[tmp++]==B[n++])
					len++;
				res=max(res,len);
			}
		}
		return res;
    }
};
