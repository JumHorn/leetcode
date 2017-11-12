#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        double temp;
        for(long i=0;i*i<=c;i++)
        {
            temp=sqrt(c-i*i);
            if(temp==(int)temp)
            {
                return true;
            }
        }
        return false;
    }
};

//solution0 只要把int i 改为long i不会越界即可
// class Solution0 {
// public:
//     bool judgeSquareSum(int c) {
//         int temp;
//         double real;
//         real = sqrt(c);
//         temp=(int)real;
//         if(real==temp)
//         {
//             return true;
//         }
//         for(int i=0;i*i<c;i++)
//         {
//             real=sqrt(c-i*i);
//             temp=(int)real;
//             if(real==temp)
//             {
//                 return true;
//             }
//         }
//         return false;
//     }
// };
