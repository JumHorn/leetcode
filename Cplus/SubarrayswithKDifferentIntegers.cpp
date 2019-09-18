#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
		int res=0;
		for(int i=0;i<(int)A.size()-K;i++)
		{
			unordered_set<int> s;
			for(int j=i;j<=(int)A.size();j++)
			{
				s.insert(A[j]);
				if(s.size()==K)
					res++;
				else if(s.size()>K)
					break;
			}
		}
		return res;		
    }
};
