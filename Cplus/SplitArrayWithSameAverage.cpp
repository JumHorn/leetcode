#include<vector>
#include<numeric>
#include<iostream>
using namespace std;

class Solution {
	double target;
public:
    bool splitArraySameAverage(vector<int>& A) {
		target=accumulate(A.begin(),A.end(),0)*1.0/A.size();
		return combinaton(A,0,0,0);        
    }
	
	bool combinaton(vector<int>& A,int start,int sum,int num)
	{
        if(A.size()>20)
        {
            if(num>A.size()/4)
                return false;
        }
        if(num>A.size()/2)
            return false;
		if(num!=0&&sum*1.0/num==target)
			return true;
		for(int i=start;i<(int)A.size();i++)
        {

			if(combinaton(A,i+1,sum+A[i],num+1))
				return true;
        }
		return false;
	}
};