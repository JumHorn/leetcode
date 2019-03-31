#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
		for(int i=0;i<(int)shifts.size();i++)
			for(int j=0;j<i;j++)
				shifts[j]=shifts[i]%26+shifts[j]%26;		
		for(int i=0;i<(int)shifts.size();i++)
			S[i]=(S[i]-'a'+shifts[i])%26+'a';
		return S;
    }
};
