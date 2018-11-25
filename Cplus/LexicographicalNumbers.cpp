#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
		vector<int> res(n,0);
		for(int i=0;i<n;i++)
			res[i]=i+1;
		sort(res.begin(),res.end(),*this);
		return res;		
    }

	bool operator()(int a,int b)
	{
		return to_string(a)<to_string(b);
	}
};
