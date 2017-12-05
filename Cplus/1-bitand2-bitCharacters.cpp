#include<iostream>
#include<vector>
using namespace std;
//倒数第一个是0，从倒数第二个统计连续1的个数，如果是奇数，false
//如果是偶数，就是正确了，不必再统计了
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits[bits.size()-1]==1)
        {
            return false;
        }
        int num1=0,t=bits.size()-2;
        while(t>=0&&bits[t]==1)
        {
            num1++;
            t--;
        }
        if(num1%2==1)
        {
            return false;
        }
        return true;
    }
};