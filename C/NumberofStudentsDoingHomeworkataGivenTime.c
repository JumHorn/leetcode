
int busyStudent(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime)
{
	int res = 0;
	for (int i = 0; i < startTimeSize; ++i)
	{
		if (queryTime >= startTime[i] && queryTime <= endTime[i])
			++res;
	}
	return res;
}
