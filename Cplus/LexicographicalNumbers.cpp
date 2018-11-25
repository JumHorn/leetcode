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

//Just repeatedly try from 1 to 9, 1 -> 10 -> 100 first, and then plus 1 to the deepest number. Take 13 as example:
//1 -> 10 -> (100) -> 11 -> (110) -> 12 -> (120) -> 13 -> (130) -> (14) -> 2 -> (20) ... -> 9 -> (90)
//
//class Solution {
//public:
//    vector<int> lexicalOrder(int n) {
//        vector<int> res;
//        helper(1, n, res);
//        return res;
//    }
//
//    void helper(int target, int n, vector<int>& res) {
//        if (target > n) return;
//        res.push_back(target);
//        helper(target * 10, n, res);
//        if (target % 10 != 9) helper(target+1, n, res);
//    }
//};
