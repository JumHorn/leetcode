#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
	string maskPII(string S)
	{
		string res;
		int n = S.length();
		if (isalpha(S[0]))
		{
			int i = 0;
			while (i < n && S[i] != '@')
			{
				S[i] = tolower(S[i]);
				i++;
			}
			res = res + S[0] + "*****" + S[i - 1];
			int j = i;
			while (++j < n)
				S[j] = tolower(S[j]);
			res += S.substr(i);
		}
		else
		{
			int count = 0, i = n;
			string numer;
			bool flag = false;
			while (--i >= 0)
			{
				if (isdigit(S[i]))
				{
					count++;
					numer = S[i] + numer;
				}
				else if (S[i] == '+')
					flag = true;
			}
			if (count == 11)
				res = "+*-***-***-" + numer.substr(numer.size() - 4);
			else if (count == 12)
				res = "+**-***-***-" + numer.substr(numer.size() - 4);
			else if (count == 13)
				res = "+***-***-***-" + numer.substr(numer.size() - 4);
			else
				res = "***-***-" + numer.substr(numer.size() - 4);
		}
		return res;
	}
};
