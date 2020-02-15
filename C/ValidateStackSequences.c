

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
	int i = -1, j = 0;
	for (int k = 0; k < pushedSize; k++)
	{
		if (popped[j] == pushed[k])
		{
			j++;
			while (i != -1 && popped[j] == pushed[i])
			{
				j++;
				i--;
			}
		}
		else
			pushed[++i] = pushed[k];
	}
	while (j < poppedSize)
	{
		if (popped[j] != pushed[i])
			return false;
		j++;
		i--;
	}
	return true;
}

