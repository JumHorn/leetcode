#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
		for(int odd=1,even=0;odd<(int)A.size();)
		{
			while(odd<(int)A.size()&&A[odd]%2==1)
				odd+=2;
			while(even<(int)A.size()&&A[even]%2==0)
				even+=2;
			if(odd<(int)A.size())
            {
                swap(A[odd],A[even]);
                odd+=2;
                even+=2;
            }
		}
		return A;
    }
};
