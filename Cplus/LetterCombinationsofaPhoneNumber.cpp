#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        unordered_map<char,string> m;
		m['2']="abc";
		m['3']="def";
		m['4']="ghi";
		m['5']="jkl";
		m['6']="mno";
		m['7']="pqrs";
		m['8']="tuv";
		m['9']="wxyz";
		string tmp(digits.size(),'\0');
		Combinations(res,m,digits,0,tmp);
		return res;
    }

	void Combinations(vector<string>& res,unordered_map<char,string>& m,string& digits,int start,string& com)
	{
		if(start==(int)digits.size())
			res.push_back(com);
		for(int i=0;i<(int)m[digits[start]].size();i++)
		{
			com[start]=m[digits[start]][i];
			Combinations(res,m,digits,start+1,com);
		}
	}
};
