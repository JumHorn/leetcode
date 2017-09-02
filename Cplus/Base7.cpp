#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
		stringstream ss;
		string result,symbol="";
		if(num==0)
			return "0";
		if(num<0)
		{
            num=-num;
            symbol="-";
		}
		while(num)
		{
			ss<<num%7;
			num/=7;
		}
		result=ss.str();
		reverse(result.begin(),result.end());
		result.insert(0,symbol);
		
		return result;
    }
};
