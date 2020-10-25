#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	char slowestKey(vector<int> &releaseTimes, string keysPressed)
	{
		vector<int> time(26);
		time[keysPressed[0] - 'a'] = releaseTimes[0];
		int N = keysPressed.length();
		for (int i = 1; i < N; ++i)
		{
			int index = keysPressed[i] - 'a';
			time[index] = max(time[index], releaseTimes[i] - releaseTimes[i - 1]);
		}
		int res = 25;
		for (int i = 25; i >= 0; --i)
		{
			if (time[i] > time[res])
				res = i;
		}
		return res + 'a';
	}
};