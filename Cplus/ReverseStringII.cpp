#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
	public:
		string reverseStr(string s, int k) {
            int i;
			for(i=1;2*i*k-k<=s.length();i++)
			{
				reverse(&s[(i-1)*k*2],&s[(i-1)*k*2+k]);
            }
            reverse(&s[(i-1)*2*k],&s[s.length()]);
			return s;
		}
};
