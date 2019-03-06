#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
        for(int i=0;i<(int)A.size();i++)
		{
			int tmp=A[0].size();
		    for(int j=0;j<tmp/2+(tmp&1);j++)
		    {
		        if(A[i][j]==A[i][tmp-j-1])
                {
		        	A[i][j]^=1;
                    A[i][tmp-j-1]=A[i][j];
                }
		    }
		}
		return A;
    }
};
