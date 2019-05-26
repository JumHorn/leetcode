#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
		int n=ratings.size();
		if(n<2)
			return n;
		//local min/max value and there index
		int res=0,maxi=0,candies=1,mini=0,i=1;
		while(i<n)
		{
			if(ratings[i-1]<ratings[i])
			{
				mini=i-1;
				candies=1;
				while(i<n&&ratings[i-1]<ratings[i])
				{
					res+=candies++;
					i++;
				}
                if(i==n)
                {
                    res+=candies;
                }
				maxi=i-1;
			}
			else if(ratings[i-1]>ratings[i])
			{
				maxi=i-1;
				int tmp=candies;
				candies=1;
				while(i<n&&ratings[i-1]>=ratings[i])
				{
					res+=candies--;
					i++;
				}
				mini=i-1;
				if(candies<1)
				{
					res+=(1-candies)*(mini-maxi+1);
				}
				if(tmp>2-candies)
					res+=tmp-(2-candies);
			}
			else
			{
				i++;
				res+=candies;
			}
		}
		return res;
    }
};
