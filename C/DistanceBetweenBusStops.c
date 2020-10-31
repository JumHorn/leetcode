
int distanceBetweenBusStops(int *distance, int distanceSize, int start, int destination)
{
	int clock = 0, counter_clock = 0, N = distanceSize;
	for (int i = start; i != destination; i = (i + 1) % N)
		clock += distance[i];
	for (int i = start; i != destination;)
	{
		i = ((i - 1) + N) % N;
		counter_clock += distance[i];
	}
	return clock < counter_clock ? clock : counter_clock;
}