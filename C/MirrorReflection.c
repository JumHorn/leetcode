

int mirrorReflection(int p, int q)
{
	int n = 0, direction = 0;
	while (++n > 0)
	{
		if (n * q % p == 0)
		{
			if (direction == 0)
				return n * q / p % 2;
			return 2;
		}
		direction = 1 - direction;
	}
	return 0;
}

