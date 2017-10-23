#include<iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<6)
        {
            return false;
        }
        int i=2,sum=0;
        while(i*i<num)
        {
            if(num%i==0)
            {
                sum+=i+num/i;
            }
            i++;
        } 
        if(i*i==num)
        {
            sum+=i;
        }
        return sum+1==num;
    }
};