#include<cmath>
using namespace std;

class Solution {
	int dr[8];
    int dc[8];
public:
	Solution():dr({2, 2, 1, 1, -1, -1, -2, -2}),dc({1, -1, 2, -2, 2, -2, 1, -1}){}
    double knightProbability(int N, int K, int r, int c) {
        int inner=0;
		probability(N,K,r,c,inner);
		return 1.0*inner/pow(8,K);
    }

	void probability(int N,int K,int r,int c,int& inner)
	{
		if(r<0||r>=N||c<0||c>=N)
			return;
        if(K==0)
        {
            inner++;
            return;
        }
		for(int i=0;i<8;i++)
		{
			probability(N,K-1,r+dr[i],c+dc[i],inner);
		}
	}
};
