#include<vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
		if(A.size()<2)
			return true;		
		int i=1;
		while(i<(int)A.size()&&A[i-1]==A[i])
			i++;
		if(i>=(int)A.size()-1)
			return true;
		if(A[i]-A[i-1]>0)
		{
			while(i<(int)A.size()&&A[i]-A[i-1]>=0)
				i++;
			if(i!=(int)A.size())
				return false;
		}
		else
		{
			while(i<(int)A.size()&&A[i]-A[i-1]<=0)
				i++;
			if(i!=(int)A.size())
				return false;
		}
		return true;
    }
};
