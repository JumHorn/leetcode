#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
		vector<int> res(A.size(),INT_MIN);
		sort(A.begin(),A.end());
		for(vector<int>::size_type i=0;i<B.size();i++)
		{
			for(vector<int>::size_type j=0;j<A.size();j++)
				if(A[j]>B[i])
				{
					res[i]=A[j];
					A[j]=INT_MIN;
					break;
				}
		}
		for(vector<int>::size_type i=0,j=0;i<res.size();i++)
		{
			if(res[i]==INT_MIN)
			{
				while(A[j]==INT_MIN)
					j++;
				res[i]=A[j];
			}
		}
		return res;
    }
};
