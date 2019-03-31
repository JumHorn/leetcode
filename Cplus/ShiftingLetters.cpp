#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
		for(int i=shifts.size()-2;i>=0;i--)
			shifts[i]=shifts[i]%26+shifts[i+1]%26;
		for(int i=0;i<(int)shifts.size();i++)
			S[i]=(S[i]-'a'+shifts[i])%26+'a';
		return S;
    }
};
