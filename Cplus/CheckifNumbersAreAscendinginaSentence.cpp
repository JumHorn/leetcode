#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	bool areNumbersAscending(string s)
	{
		stringstream ss(s);
		string word;
		int pre = -1;
		while (ss >> word)
		{
			if (isdigit(word[0]))
			{
				int cur = stoi(word);
				if (cur <= pre)
					return false;
				pre = cur;
			}
		}
		return true;
	}
};