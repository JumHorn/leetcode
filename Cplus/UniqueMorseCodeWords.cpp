#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
		vector<string> morsecode=
		{
		 ".-","-...","-.-.","-..",".","..-.","--.",
		 "....","..",".---","-.-",".-..","--","-.",
		 "---",".--.","--.-",".-.","...","-","..-",
		 "...-",".--","-..-","-.--","--.."
		};
		unordered_set<string> s;
		for(int i=0;i<(int)words.size();i++)
		{
			string tmp;
			for(int j=0;j<(int)words[i].length();j++)
				tmp+=morsecode[words[i][j]-'a'];
			s.insert(tmp);
		}
		return s.size();
    }
};
