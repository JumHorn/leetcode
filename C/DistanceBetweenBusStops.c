int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination)
{
	int clock = 0, counter_clock = 0;
	int i = start;
	while (i != destination)
	{
		clock += distance[i];
		i = (i + 1) % distanceSize;
	}
	i = start;
	while (i != destination)
	{
		i = ((i - 1) + distanceSize) % distanceSize;
		counter_clock += distance[i];
	}
	if (clock < counter_clock)
		return clock;
	return counter_clock;
}
