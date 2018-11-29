#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
		vector<int> hash(26);
		for(int i=0;i<tasks.size();i++)
			hash[tasks[i]-'A']++;
		sort(hash.begin(),hash.end(),greater<int>());
		int res=0;
		while(hash[0]>0)
		{
			for(int i=0;i<=n;i++)
			{
				if(hash[0]==0)
					break;
				if(i<26&&hash[i]>0)
					hash[i]--;
				res++;
			}
			sort(hash.begin(),hash.end(),greater<int>());
		}		
		return res;
    }
};
