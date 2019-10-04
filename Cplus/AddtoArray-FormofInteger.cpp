#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
		reverse(A.begin(),A.end());        
		int flag=0,i=0;
		while(K!=0||flag==1)
		{
			if(i==(int)A.size())
				A.push_back(0);
			int tmp=A[i]+K%10+flag;
			if(tmp>=10)
			{
				A[i]=tmp-10;
				flag=1;
			}
			else
			{
				A[i]=tmp;
				flag=0;
			}
			K/=10;
			i++;
		}
		reverse(A.begin(),A.end());
		return A;
    }
};
