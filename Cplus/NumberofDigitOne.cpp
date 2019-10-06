#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int res=0;
        for(long long m=1;m<=n;m*=10)
        {
            int a=n/m,b=n%m;
            if(a%10==1)
                res+=a/10*m+b+1;
            else if(a%10==0)
                res+=a/10*m;
            else
                res+=(a/10+1)*m;
        }
        return res;
    }
};