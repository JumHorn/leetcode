#include<iostream>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int result=0,temp=0;
        if(A.size()<3)
        {
            return 0;
        }

        //Get the difference between two adjacent numbers
        for(int i=1;i<A.size();i++)
        {
            A[i-1]=A[i]-A[i-1];
        }

        for(int i=1;i<A.size()-1;i++)
        {
            if(A[temp]==A[i])
            {
                continue;
            }
            else
            {
                int num = i-temp;
                temp = i;
                if(num>1)
                {
                    result+=getslacenum(num+1);
                }
            }
        }
        int num = A.size()-1-temp;
        if(num>1)
        {
            result+=getslacenum(num+1);
        }

        return result;
    }

    int getslacenum(int length)
    {
        int sum=0;
        for(int l=3;l<=length;l++)
        {
            sum+=length-(l-1);
        }
        return sum;
    }
};

//相隔超过1的等差数列，不需要思考
class Solution0 {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sum=0;
        for(int l=3;l<=A.size();l++)
        {
            for(int i=0;l+(l-1)*i<=A.size();i++)
            {
                sum+=A.size()-(l+(l-1)*i-1);
            }
        }
        return sum;
    }
};

//dynamic programming java code
// public class Solution {
//     public int numberOfArithmeticSlices(int[] A) {
//         int[] dp = new int[A.length];
//         int sum = 0;
//         for (int i = 2; i < dp.length; i++) {
//             if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
//                 dp[i] = 1 + dp[i - 1];
//                 sum += dp[i];
//             }
//         }
//         return sum;
//     }
// }