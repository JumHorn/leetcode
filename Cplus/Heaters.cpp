#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//一步小小的改动，排名提升70%
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int temp,result=0,j=0;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        for(int i=0;i<houses.size();i++)
        {
            if(houses[i]<=heaters[0])
            {
                temp = heaters[0]-houses[i];
            }
            else if(houses[i]>=heaters[heaters.size()-1])
            {
                temp = houses[i]-heaters[heaters.size()-1];
            }
            else
            {
                for(;j<heaters.size()-1;j++)
                {
                    if((houses[i]-heaters[j])>=0&&(houses[i]-heaters[j+1])<=0)
                    {
                        temp = (houses[i]-heaters[j])<(heaters[j+1]-houses[i])?(houses[i]-heaters[j]):(heaters[j+1]-houses[i]);
                        break;
                    }
                }
            }
            if(temp>result)
            {
                result=temp;
            }
        }
        return result;
    }
};
//每一个house寻找一个最近的headter，取所有house最近heater的最小值
class Solution0 {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int temp,result=0;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        for(int i=0;i<houses.size();i++)
        {
            if(houses[i]<=heaters[0])
            {
                temp = heaters[0]-houses[i];
            }
            else if(houses[i]>=heaters[heaters.size()-1])
            {
                temp = houses[i]-heaters[heaters.size()-1];
            }
            else
            {
                for(int j=0;j<heaters.size()-1;j++)
                {
                    if((houses[i]-heaters[j])>=0&&(houses[i]-heaters[j+1])<=0)
                    {
                        temp = (houses[i]-heaters[j])<(heaters[j+1]-houses[i])?(houses[i]-heaters[j]):(heaters[j+1]-houses[i]);
                        break;
                    }
                }
            }
            if(temp>result)
            {
                result=temp;
            }
        }
        return result;
    }
};

int main()
{
    int a[4] ={1,2,3,4};
    int b[2]={1,4};
    vector<int> c(a,a+4);
    vector<int> d(b,b+2);
    Solution sol;
    int t = sol.findRadius(c,d);
    cout<<t<<endl;
}