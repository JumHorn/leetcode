
int maxCandies(int *status, int statusSize, int *candies, int candiesSize, int **keys, int keysSize, int *keysColSize, int **containedBoxes, int containedBoxesSize, int *containedBoxesColSize, int *initialBoxes, int initialBoxesSize)
{
	int size = 20000, front = 0, rear = 0, queue[size]; //opened box
	for (int i = 0; i < initialBoxesSize; ++i)
	{
		if (status[initialBoxes[i]] == 0) //0 means we cannot seen this closed box
			status[initialBoxes[i]] = 3;  //3 means we have this closed box in hand
		else
		{
			queue[rear] = initialBoxes[i];	 //we get this open box
			rear = (rear - 1 + size) % size; //push back
		}
	}
	int res = 0;
	while (front != rear)
	{
		int n = queue[front];
		front = (front - 1 + size) % size; //pop front

		if (status[n] == -1) //-1 means already take all candies
			continue;
		status[n] = -1;
		res += candies[n];

		for (int i = 0; i < keysColSize[n]; ++i)
		{
			if (status[keys[n][i]] == -1)
				continue;
			if (status[keys[n][i]] == 3)
			{
				queue[rear] = keys[n][i];		 //we get this open box
				rear = (rear - 1 + size) % size; //push back
			}
			else
				status[keys[n][i]] = 2; //2 means we have this box's key
		}
		for (int i = 0; i < containedBoxesColSize[n]; ++i)
		{
			if (status[containedBoxes[n][i]] == -1)
				continue;
			if (status[containedBoxes[n][i]] >= 1)
			{
				queue[rear] = containedBoxes[n][i]; //we get this open box
				rear = (rear - 1 + size) % size;	//push back
			}
			else
				status[containedBoxes[n][i]] = 3;
		}
	}
	return res;
}