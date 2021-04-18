#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool checkIfPangram(string sentence)
	{
		vector<bool> v(26);
		for (auto c : sentence)
			v[c - 'a'] = true;
		for (auto b : v)
		{
			if (!b)
				return false;
		}
		return true;
	}
};