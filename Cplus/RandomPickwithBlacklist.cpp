#include<vector>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
	unordered_map<int,int> black;
	int n;
public:
    Solution(int N, vector<int>& blacklist) {
		unordered_set<int> tmp(blacklist.begin(),blacklist.end());
		n=N-blacklist.size();
		N--;
		for(int i=0;i<(int)blacklist.size();i++)
		{
			if(blacklist[i]<n)
			{
				while(tmp.find(N)!=tmp.end())
					N--;
				black[blacklist[i]]=N;
				N--;
			}
		}
    }
    
    int pick() {
		int res=rand()%n;
		if(black.find(res)==black.end())
			return res;
		return black[res];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
