#include <regex>
#include <string>
using namespace std;

class Solution
{
public:
	string defangIPaddr(string address)
	{
		return regex_replace(address, regex("[.]"), "[.]");
	}
};