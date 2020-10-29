#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
	string reverseOnlyLetters(string S)
	{
		int i = 0, j = (int)S.length() - 1;
		while (i < j)
		{
			if (!isalpha(S[i]))
				++i;
			else if (!isalpha(S[j]))
				--j;
			else
				swap(S[i++], S[j--]);
		}
		return S;
	}
};