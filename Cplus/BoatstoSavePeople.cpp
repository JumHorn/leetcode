#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
		sort(people.begin(),people.end());
		return numRescueBoats(people,limit,0,people.size());
    }

	int numRescueBoats(vector<int>& people,int limit,int start,int end)
	{
		if(end-start<=1)
			return end-start;
		for(int i=start+1;i<end;i++)
			if(people[start]+people[i]>limit)
				return end-i+numRescueBoats(people,limit,start,i);
		return 1+numRescueBoats(people,limit,start+1,end-1);

	}
};
