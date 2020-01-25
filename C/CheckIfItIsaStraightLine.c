

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize)
{
	for (int i = 2; i < coordinatesSize; i++)
	{
		if ((coordinates[i][1] - coordinates[i - 2][1]) * (coordinates[i - 1][0] - coordinates[i - 2][0]) !=
			(coordinates[i - 1][1] - coordinates[i - 2][1]) * (coordinates[i][0] - coordinates[i - 2][0]))
			return false;
	}
	return true;
}

