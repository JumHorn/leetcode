#include<iostream>
using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long i=num;
        while(i*i>num)
        {
            i = (i+num/i)/2;
        }
        return i*i==num;
    }
};

//time limit exceeded
// class Solution0 {
// public:
//     bool isPerfectSquare(int num) {
//         if(num<2)
//         {
//             return true;
//         }
//         int i=3,t=0;
//         while(num%2==0)
//         {
//             t++;
//             num/=2;
//         }
//         if(t%2!=0)
//         {
//             return false;
//         }
//         while(i*i<=num)
//         {
//             t=0;
//             while(num%i==0)
//             {
//                 t++;
//                 num/=i;
//             }
//             if(t%2!=0)
//             {
//                 return false;
//             }
//             else
//             {
//                 if(num==1)
//                 {
//                     return true;
//                 }
//             }
//             i+=2;
//         }
//         return false;
//     }
// };


//other solution
// A square number is 1+3+5+7+...
// public boolean isPerfectSquare(int num) {
//     int i = 1;
//     while (num > 0) {
//         num -= i;
//         i += 2;
//     }
//     return num == 0;
// }