#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool areSentencesSimilar(string sentence1, string sentence2)
	{
		if (sentence1.length() > sentence2.length())
			swap(sentence1, sentence2);
		stringstream ss1(sentence1), ss2(sentence2);
		vector<string> v1, v2;
		string word;
		while (ss1 >> word)
			v1.push_back(word);
		while (ss2 >> word)
			v2.push_back(word);
		int i = 0, j = (int)v1.size() - 1;
		for (auto &s : v2)
		{
			if (i > j || s != v1[i])
				break;
			++i;
		}
		if (i > j)
			return true;
		for (int k = (int)v2.size() - 1; k >= 0 && j >= 0; --k)
		{
			if (v2[k] != v1[j])
				break;
			--j;
		}
		return j < i;
	}
};