#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int k=1;
        for(int i=1;i*i<=area;i++)
        {
            if(area%i==0)
            {
                k=i;
            }
        }
        if(k<area/k)k=area/k;
        int array[] = {k,area/k};
        vector<int> result(array,array+2);
        //这种方式很慢
        // result.push_back(k);
        // result.push_back(area/k);
        return result;
    }
};

int main()
{
    Solution sol;
    cout<<sol.constructRectangle(2147483647)[0]<<endl;
    
}