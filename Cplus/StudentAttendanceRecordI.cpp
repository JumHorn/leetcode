#include<iostream>
using namespace std;
//这里遍历了两次
class Solution {
public:
    bool checkRecord(string s) {
		int absent,late;
		absent =count(s.begin(),s.end(),'A');
		if(absent>1)
		{
			return false;
		}
		late = s.find("LLL");
		if(late>=0)
		{
			return false;
		}
		return true;
    }
};

//more than two continuous 'L'
class Solution0 {
public:
    bool checkRecord(string s) {
		int absent,late;
		absent =count(s.begin(),s.end(),'A');
		if(absent>1)
		{
			return false;
		}
		late = count(s.begin(),s.end(),'L');
		if(late>2)
		{
			return false;
		}
		return true;
    }
};
