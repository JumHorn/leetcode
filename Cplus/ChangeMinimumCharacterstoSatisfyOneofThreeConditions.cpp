#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minCharacters(string a, string b)
	{
		int N1 = a.length(), N2 = b.length();
		vector<int> acount(26), bcount(26);
		int amost = 0, bmost = 0;
		for (auto c : a)
			amost = max(amost, ++acount[c - 'a']);
		for (auto c : b)
			bmost = max(bmost, ++bcount[c - 'a']);
		int res = N1 - amost + N2 - bmost;
		for (int i = 1; i < 26; ++i)
		{
			acount[i] += acount[i - 1];
			bcount[i] += bcount[i - 1];
		}
		for (int i = 0; i < 25; ++i)
		{
			res = min(res, acount[25] - acount[i] + bcount[i]);
			res = min(res, bcount[25] - bcount[i] + acount[i]);
		}
		return res;
	}
};