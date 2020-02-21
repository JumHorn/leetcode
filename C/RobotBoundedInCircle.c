
bool isRobotBounded(char* instructions)
{
	int direction[4] = {0}, d = 0;
	for (int i = 0; i < 4; i++)
	{
		char* tmp = instructions;
		while (*tmp)
		{
			if (*tmp == 'G')
				direction[d]++;
			else if (*tmp == 'L')
				d = (d - 1 + 4) % 4;
			else
				d = (d + 1) % 4;
			++tmp;
		}
	}
	return direction[0] == direction[2] && direction[1] == direction[3];
}

