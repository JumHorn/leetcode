#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
		vector<string> v(nums.size());
		for(int i=0;i<(int)nums.size();i++)
			v[i]=to_string(nums[i]);
		sort(v.begin(),v.end(),*this);
	   	string res;
		int i=0;
		while(i<(int)v.size()&&v[i]=="0")
			i++;
		for(;i<(int)v.size();i++)
			res+=v[i];
		if(res.empty())
			return "0";
		return res;	
    }

	bool operator()(const string& lhs,const string& rhs)
	{
		return lhs+rhs>rhs+lhs;
	}
};
