
#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

char *restoreString(char *s, int *indices, int indicesSize)
{
	for (int i = 0; i < indicesSize; ++i)
	{
		for (int j = i; indices[j] >= 0; j = ~indices[j])
		{
			swap(s[i], s[indices[j]]);
			indices[j] = ~indices[j];
		}
	}
	return s;
}