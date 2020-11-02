
#define max(a, b) (((a) > (b)) ? (a) : (b))

char slowestKey(int* releaseTimes, int releaseTimesSize, char* keysPressed)
{
	int time[26] = {0};
	time[keysPressed[0] - 'a'] = releaseTimes[0];
	for (int i = 1; i < releaseTimesSize; ++i)
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
