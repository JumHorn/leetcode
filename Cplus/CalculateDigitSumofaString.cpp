#include <string>
using namespace std;

class Solution
{
public:
	string digitSum(string s, int k)
	{
		while (s.length() > k)
		{
			string next_s;
			int N = s.length(), sum = 0;
			for (int i = 0; i < N; ++i)
			{
				sum += s[i] - '0';
				if ((i + 1) % k == 0)
				{
					next_s += to_string(sum);
					sum = 0;
				}
			}
			if (N % k != 0)
				next_s += to_string(sum);
			s = next_s;
		}
		return s;
	}
};