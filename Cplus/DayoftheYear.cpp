#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        vector<int> month={0,31,28,31,30,31,30,31,31,30,31,30,31};
		int res=0;
		int m=stoi(date.substr(5,2));
		for(int i=1;i<m;i++)
			res+=month[i];
		res+=stoi(date.substr(8,2));
		int y=stoi(date.substr(0,4));
		if(m>2&&((y%400==0)||(y%4==0&&y%100!=0)))
			return res+1;
		return res;
    }
};
