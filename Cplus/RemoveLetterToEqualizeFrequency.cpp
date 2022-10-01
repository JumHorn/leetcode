#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool equalFrequency(string word)
	{
		vector<int> count(26), freq(101);
		int N = word.size();
		for (int i = 0; i < N; ++i)
		{
			int n = word[i] - 'a';
			--freq[count[n]];
			int c = ++count[n];
			++freq[c];
			//already the same freq, the following number shoud be removed
			if (freq[c] * c == i + 1 && i + 1 == N - 1)
				return true;
			//the other numbers have the same freq d
			int d = i + 1 - freq[c] * c;
			if (i == N - 1 && freq[d] == 1 && (d == 1 || d == c + 1))
				return true;
		}
		return false;
	}
};