/*
dynamic programming
A(m,n)=A(m-1,n)+A(m,n-1)
A(1,n)=1
A(m,1)=1
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
		if(m==1||n==1)
		{
			return 1;
		}
		return uniquePaths(m-1,n)+uniquePaths(m,n-1);        
    }
};
