#include<cmath>
#include<vector>
#include<map>
using namespace std;

class Solution {
	int dr[8];
    int dc[8];
public:
	Solution():dr({2, 2, 1, 1, -1, -1, -2, -2}),dc({1, -1, 2, -2, 2, -2, 1, -1}){}
    double knightProbability(int N, int K, int r, int c) {
        map<vector<int>,int> m;
		long long inner=probability(N,K,r,c,m);
        double res=inner*1.0;
        for(int i=0;i<K;i++)
		    res/=8;
        return res;
    }

	long long probability(int N,int K,int r,int c,map<vector<int>,int>& m)
	{
		if(r<0||r>=N||c<0||c>=N)
			return 0;
        if(K==0)
            return 1;
		long long sum=0;
		for(int i=0;i<8;i++)
		{
			vector<int> tmp(3);
			tmp[0]=r+dr[i];
			tmp[1]=c+dc[i];
			tmp[2]=K;
			if(m.find(tmp)==m.end())
			{
				int res=probability(N,K-1,r+dr[i],c+dc[i],m);
				m[tmp]=res;
                sum+=res;
			}
			else
				sum+=m[tmp];
		}
		return sum;
	}
};
