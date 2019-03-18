#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
		int start=0,end=A.size()-1;
		while(start<end)
		{
			while(start<end&&(A[start]&1)==0)
				start++;
			while(start<end&&(A[end]&1)==1)
				end--;
			swap(A[start],A[end]);
		}		
		return A;
    }
};
