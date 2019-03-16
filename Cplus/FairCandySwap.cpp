#include<vector>
#include<map>
#include<numeric>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		map<int,int> ma,mb;
		int sumA=accumulate(A.begin(),A.end(),0);
		int sumB=accumulate(B.begin(),B.end(),0);
		int avg=(sumA+sumB)/2;
		for(int i=0;i<(int)B.size();i++)
			mb[B[i]]=1;
		vector<int> res(2);
		for(int i=0;i<(int)A.size();i++)
		{
			if(mb.count(avg+A[i]-sumA)>0)
			{
				res[0]=A[i];
				res[1]=avg+A[i]-sumA;
			}
		}
	    return res;	
    }
};
