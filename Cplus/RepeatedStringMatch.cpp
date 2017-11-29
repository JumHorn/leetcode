#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int result=1;
        string temp=A;
        while(A.size()<B.size())
        {
            A+=temp;
            result++;
        }
        if(A.find(B)!=string::npos)
        {
            return result;
        }
        else
        {
            A+=A;
            if(A.find(B)!=string::npos)
            {
                return result+1;
            }
        }
        return -1;
    }
};

//time limit exceeded
// class Solution0 {
// public:
//     int repeatedStringMatch(string A, string B) {
//         int result=1;
//         string temp=A;
//         do
//         {
//             if(A.find(B)==string::npos)
//             {
//                 A+=temp;
//                 result++;
//             }
//             else
//             {
//                 return result;
//             }
//         }while(result<3||A.size()<=2*B.size());
//         return -1;
//     }
// };