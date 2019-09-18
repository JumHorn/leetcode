#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& A) {
		unordered_map<int,int> m;
 		for(int i=0;i<(int)A.size();i++)
			for(int j=0;j<(int)A.size();j++)
				++m[A[i]&A[j]];	
		int res=0;
		for(int i=0;i<(int)A.size();i++)
            for(auto n : m)
                if((A[i]&n.first)==0)
			        res+=n.second;
		return res;
    }
};