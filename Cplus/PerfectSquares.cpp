#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
		int i=1;
		while(i*i<n)
			i++;
		if(i*i==n)
			return 1;
		int m=INT_MAX;
		for(int j=i-1;j>=1;j--)
		{
			m=min(m,1+numSquares(n-j*j));
		}
		return m;
    }
};
