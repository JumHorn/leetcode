#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //第一次思路，每次都是后面大于前面则赚
        if(prices==0)
        {
            return 0;
        }
        int sum=0,i;
        for(i=0;i<prices.size()-1;i++)
        {
            if(prices[i]<prices[i+1])
                sum+=prices[i+1]-prices[i];
        }
        return sum;
        // int max=prices[0],min=prices[0];
        // for(int i=1;i<prices.size();i++)
        // {
        //     if(prices[i]>max)max=prices[i];
        //     if(prices[i]<min)min=prices[i];
        // }
        // return max-min;
    }
};

int main()
{
    vector<int> v;
    cout<<v.size()<<endl;
    Solution sol;
    cout<<sol.maxProfit(v)<<endl;

}