#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
		vector<int> res(n);
        res[0]=1;
        int i2=0,i3=0,i5=0;
        for(int i=1;i<n;i++)
        {
            res[i]=min(res[i2]*2,min(res[i3]*3,res[i5]*5));
            if(res[i]==res[i2]*2)
                i2++;
            if(res[i]==res[i3]*3)
                i3++;
            if(res[i]==res[i5]*5)
                i5++;
        }
        return res.back();
    }
};
