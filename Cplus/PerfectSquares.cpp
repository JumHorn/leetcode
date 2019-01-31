#include<algorithm>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
		unordered_map<int,int> calculated;
		return numSquares(calculated,n);
    }

    int numSquares(unordered_map<int,int>& calculated,int n) {
		if(calculated.find(n)!=calculated.end())
			return calculated[n];
		int i=1;
		while(i*i<n)
			i++;
		if(i*i==n)
		{
			calculated[n]=1;
			return 1;
		}
		int m=INT_MAX;
		for(int j=i-1;j>=1;j--)
		{
			m=min(m,1+numSquares(n-j*j));
            if(m==2)
            {
                calculated[n]=2;
                return 2;
            }
		}
		calculated[n]=m;
		return m;
    }
};
