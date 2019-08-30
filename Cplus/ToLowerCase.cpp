#include<string>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
		for(int i=0;i<(int)str.length();i++)
			if(str[i]>='A'&&str[i]<='Z')
				str[i]+='a'-'A';		
		return str;
    }
};
