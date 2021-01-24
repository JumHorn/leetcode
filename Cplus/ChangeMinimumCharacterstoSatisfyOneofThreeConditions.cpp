#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minCharacters(string a, string b)
	{
		int N1 = a.length(), N2 = b.length(), res;
		vector<int> acount(26), bcount(26);
		int amost = 0, bmost = 0;
		for (auto c : a)
			amost = max(amost, ++acount[c - 'a']);
		for (auto c : b)
			bmost = max(bmost, ++bcount[c - 'a']);
		res = N1 - amost + N2 - bmost;
		for (char d = 'a'; d < 'z'; ++d)
		{
			int sum1 = 0, sum2 = 0;
			for (auto c : a)
			{
				if (c > d)
					++sum1;
			}
			for (auto c : b)
			{
				if (c <= d)
					++sum1;
			}

			for (auto c : b)
			{
				if (c > d)
					++sum2;
			}
			for (auto c : a)
			{
				if (c <= d)
					++sum2;
			}
			res = min(res, sum1);
			res = min(res, sum2);
		}

		return res;
	}
};