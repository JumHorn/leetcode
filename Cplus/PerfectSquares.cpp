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


/*
class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }
        
        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Since cntPerfectSquares is a static vector, if 
        // cntPerfectSquares.size() > n, we have already calculated the result 
        // during previous function calls and we can just return the result now.
        static vector<int> cntPerfectSquares({0});
        
        // While cntPerfectSquares.size() <= n, we need to incrementally 
        // calculate the next result until we get the result for n.
        while (cntPerfectSquares.size() <= n)
        {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i*i <= m; i++)
            {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }
            
            cntPerfectSquares.push_back(cntSquares);
        }
        
        return cntPerfectSquares[n];
    }
};
*/
