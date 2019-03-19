#include<string>
#include<cctype>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
		if(S.empty())
			return S;
		int start=0,end=S.length()-1;
		while(start<end)
		{
			while(start<end&&!isalpha(S[start]))
				start++;
			while(start<end&&!isalpha(S[end]))
				end--;
			swap(S[start++],S[end--]);
		}
		return S;
    }
};
