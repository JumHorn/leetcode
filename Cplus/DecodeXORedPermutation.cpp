#include <vector>
using namespace std;

/*
a1,a2,a3,a4,...,an is a permutaion of 1,2,3,...,n
(a2^a3)^(a4^a5)^(a6^a7)^...^(an-1^an)=encoded[1]^encoded[3]^...,encoded[odd]
a1=1^2^3^,...^n^encoded[1]^encoded[3]^...,encoded[odd]
*/

class Solution
{
public:
	vector<int> decode(vector<int> &encoded)
	{
		int a1 = 0, xorall = 0, xorodd = 0, N = encoded.size();
		for (int i = 0; i <= N; ++i)
		{
			xorall ^= i;
			if (i % 2 == 1)
				xorodd ^= encoded[i];
		}
		xorall ^= N + 1;
		a1 = xorall ^ xorodd;
		vector<int> res = {a1};
		for (auto n : encoded)
			res.push_back(res.back() ^ n);
		return res;
	}
};