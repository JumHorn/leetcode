#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	bool strongPasswordCheckerII(string password)
	{
		string special = "!@#$%^&*()-+";
		if (password.size() < 8)
			return false;
		if (!any_of(password.begin(), password.end(), [](char c)
					{ return islower(c); }))
			return false;
		if (!any_of(password.begin(), password.end(), [](char c)
					{ return isupper(c); }))
			return false;
		if (!any_of(password.begin(), password.end(), [](char c)
					{ return isdigit(c); }))
			return false;
		if (!checkSpecial(special, password))
			return false;
		for (int i = 0; i < (int)password.size() - 1; ++i)
		{
			if (password[i] == password[i + 1])
				return false;
		}
		return true;
	}

	bool checkSpecial(string &str, string password)
	{
		for (auto c : str)
		{
			if (any_of(password.begin(), password.end(), [&](char ch)
					   { return c == ch; }))
				return true;
		}
		return false;
	}
};