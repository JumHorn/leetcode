#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int i=0;
        while(pow(i,2)<=x)
        {
            //cout<<i*i<<endl;  //用普通乘法精度不够
            i++;
        }
        return i-1;        
    }
};

int main()
{
    Solution sol;
    cout<<sol.mySqrt(2147395600)<<endl;//数值运算精度不够
    return 0;
}