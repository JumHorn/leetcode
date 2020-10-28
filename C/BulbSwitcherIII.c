
#define max(a, b) (((a) > (b)) ? (a) : (b))

int numTimesAllBlue(int* light, int lightSize)
{
	int bulbid = 0, res = 0;
	for (int i = 0; i < lightSize; ++i)
	{
		bulbid = max(bulbid, light[i]);
		if (bulbid == i + 1)
			++res;
	}
	return res;
}
