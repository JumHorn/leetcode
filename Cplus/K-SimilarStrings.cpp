#include<string>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int kSimilarity(string A, string B) {
		return kSimilarity(A,B,0);
	}
    int kSimilarity(string& A, string& B,int start) {
		int res=INT_MAX;
		while(start<(int)A.length()&&A[start]==B[start])
			start++;
		for(int j=start+1;j<(int)A.size();j++)
		{
			if(B[start]==A[j]&&B[j]!=A[j])
			{
				swap(A[start],A[j]);
				int tmp=kSimilarity(A,B,start+1)+1;
				res=min(tmp,res);
				swap(A[start],A[j]);
			}
		}
		if(res==INT_MAX)
			res=0;
		return res;
    }
};