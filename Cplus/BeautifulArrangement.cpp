#include <unordered_map>
using namespace std;

class Solution
{
public:
	int countArrangement(int N)
	{
		unordered_map<int, int> hash, next_hash; //{mask,count}
		hash[0] = 1;
		for (int i = 1; i <= N; ++i)
		{
			next_hash.clear();
			for (int j = 1; j <= N; ++j)
			{
				if (i % j == 0 || j % i == 0)
				{
					for (auto &iter : hash)
					{
						if ((iter.first & (1 << (j - 1))) == 0)
							next_hash[iter.first | (1 << (j - 1))] += iter.second;
					}
				}
			}
			hash.swap(next_hash);
		}
		return hash[(1 << N) - 1];
	}
};