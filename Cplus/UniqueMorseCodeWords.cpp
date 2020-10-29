#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int uniqueMorseRepresentations(vector<string> &words)
	{
		vector<string> morsecode = {
			".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
			"....", "..", ".---", "-.-", ".-..", "--", "-.",
			"---", ".--.", "--.-", ".-.", "...", "-", "..-",
			"...-", ".--", "-..-", "-.--", "--.."};
		unordered_set<string> s;
		for (auto &word : words)
		{
			string morsestr;
			for (auto &c : word)
				morsestr += morsecode[c - 'a'];
			s.insert(morsestr);
		}
		return s.size();
	}
};