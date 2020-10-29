#include <sstream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	string toGoatLatin(string S)
	{
		unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
		stringstream ss(S), res;
		string aaa = "a", word;
		while (ss >> word)
		{
			if (vowel.find(word[0]) != vowel.end())
				res << " " << word << "ma" << aaa;
			else
				res << " " + word.substr(1) << word[0] << "ma" << aaa;
			aaa += "a";
		}
		return res.str().substr(1);
	}
};