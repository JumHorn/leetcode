#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
		vector<int> index(matrix.size(),0);
		int res=2147483648;
		for(int i=0;i<k;i++)
		{
			res=INT_MAX;
			int m=0;
			for(int j=0;j<matrix.size();j++)
			{
				if(index[j]<matrix.size()&&matrix[j][index[j]]<res)
				{
					res=matrix[j][index[j]];
					m=j;
				}
			}
			index[m]++;
		}
		return res;
    }
};
