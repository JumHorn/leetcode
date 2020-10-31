#include <string>
using namespace std;

class Solution
{
public:
	string removeDuplicates(string S)
	{
		string res; //view res as stack
		for (auto c : S)
		{
			if (res.empty() || res.back() != c)
				res.push_back(c);
			else
				res.pop_back();
		}
		return res;
	}
};