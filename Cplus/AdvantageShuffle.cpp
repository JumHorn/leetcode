#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
		sort(A.begin(),A.end());
		for(vector<int>::size_type i=0;i<B.size();i++)
		{
            vector<int>::size_type j=0;
			for(j=0;j<A.size();j++)
				if(A[j]>B[i])
				{
					B[i]=A[j];
					A[j]=INT_MIN;
					break;
				}
            if(j==A.size())
                B[i]=INT_MIN;
		}
		for(vector<int>::size_type i=0,j=0;i<B.size();i++)
		{
			if(B[i]==INT_MIN)
			{
				while(A[j]==INT_MIN)
					j++;
				B[i]=A[j];
			}
		}
		return B;
    }
};
