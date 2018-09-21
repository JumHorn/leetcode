#include<iostream>
#include<cmath>
using namespace std;

//solve the problem with probability
//2^(n)+n*2^(n-1)表示absent不超过一次的总数
//(n-2)*2^(n-3)+(n-2)*2^(n-4)*(n-3)表示3个连续L的个数 n>=4
class Solution {
public:
    int checkRecord(int n) {
        int MOD = 1000000007;
        if(n==1)return 3;
        if(n==2)return 8;
        if(n==3)return 19;
        return pow(2,n)+n*pow(2,n-1)-(n-2)*pow(2,n-3)-(n-2)*(n-3)*pow(2,n-4);
    }
};