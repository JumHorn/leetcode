#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
	{
		int res = 0;
		unordered_map<int, int> hash;
		for (auto a : A)
		{
			for (auto b : B)
				++hash[a + b];
		}
		for (auto c : C)
		{
			for (auto d : D)
			{
				if (hash.find(-(c + d)) != hash.end())
					res += hash[-(c + d)];
			}
		}
		return res;
	}
};