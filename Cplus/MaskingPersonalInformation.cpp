#include <algorithm>
#include <regex>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string maskPII(string S)
	{
		string res;
		vector<string> country = {"", "+*-", "+**-", "+***-"};
		int at = S.find("@");
		if (at != string::npos) //email
		{
			transform(S.begin(), S.end(), S.begin(), ::tolower);
			return S.substr(0, 1) + "*****" + S.substr(at - 1);
		}
		S = regex_replace(S, regex("[^0-9]"), "");
		return country[S.size() - 10] + "***-***-" + S.substr(S.size() - 4);
	}
};