#include<iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        //return ~num;   //表示二进制取反 位移<<=
        if(num==0)
        return 1;
        int i=1,n=0;
        while(num)
        {
            n+=i*(num%2==1?0:1);
            i*=2;
            num/=2;
        }
        return n;
    }
};

int main()
{
    Solution sol;
    cout<<sol.findComplement(5);
    return 0;
}