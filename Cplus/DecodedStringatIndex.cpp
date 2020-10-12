#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
	string decodeAtIndex(string S, int K)
	{
		stack<pair<int, long>> s; //{index of S,decode length}
		s.push({-1, 0});
		long N = S.length(), decodelen = 0;
		for (int i = 0; i < N && decodelen < K; ++i)
		{
			if (S[i] <= '9') //isdigits
			{
				decodelen *= S[i] - '0';
				s.push({i, decodelen});
			}
			else
				++decodelen;
		}
		while (s.top().second >= K)
		{
			int index = s.top().first;
			long len = s.top().second;
			s.pop();
			K = K % (len / (S[index] - '0'));
			if (K == 0)
			{
				while (S[index] <= '9')
					--index;
				return {S[index]};
			}
		}
		return {S[s.top().first + K - s.top().second]};
	}
};