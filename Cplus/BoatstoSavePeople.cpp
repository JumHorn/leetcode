#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
		int res=0;
        make_heap(people.begin(),people.end(),greater<int>());
		while(people.size()>=2)
		{
			pop_heap(people.begin(),people.end(),greater<int>());
			int p1=people.back();
			people.pop_back();
			pop_heap(people.begin(),people.end(),greater<int>());
			int p2=people.back();
			people.pop_back();
			if(p1+p2>limit)
			{
				return res+people.size()+2;
			}
			res++;
		}
		res+=people.size();
		return res;
    }
};
