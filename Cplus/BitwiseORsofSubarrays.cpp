#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
		unordered_set<int> res,last;
		res.insert(A.front());
		last.insert(A.front());
		for(int i=1;i<(int)A.size();i++)
		{
			unordered_set<int> tmp;
			for(unordered_set<int>::iterator iter=last.begin();iter!=last.end();++iter)
				tmp.insert(*iter|A[i]);
			tmp.insert(A[i]);
			res.insert(tmp.begin(),tmp.end());
			last=tmp;
		}
		return res.size();	
    }
};
