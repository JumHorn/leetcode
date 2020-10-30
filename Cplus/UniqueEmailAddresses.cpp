#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int numUniqueEmails(vector<string> &emails)
	{
		unordered_set<string> s;
		for (auto &email : emails)
		{
			int i = 0, j = 0;
			for (; email[j] != '+' && email[j] != '@'; ++j)
			{
				if (email[j] != '.')
					email[i++] = email[j];
			}
			while (email[j] != '@')
				++j;
			s.insert(email.substr(0, i) + email.substr(j));
		}
		return s.size();
	}
};