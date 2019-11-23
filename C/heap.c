#define swap(a, b) \
	if ((a) != (b)) (a) ^= (b) ^= (a) ^= (b)

void pushheap(int* data, int hole)
{
	int val = data[hole];
	for (; hole > 0 && data[(hole - 1) / 2] < val; hole = (hole - 1) / 2)
		data[hole] = data[(hole - 1) / 2];
	data[hole] = val;
}

void popheap(int* data, int last)
{
	int val = data[0], hole = 0, index = 2 * 0 + 2;
	for (; index < last; index = index * 2 + 2)
	{
		if (data[index - 1] > data[index])
			index--;
		data[(index - 1) / 2] = data[index];
		hole = index;
	}
	if (index == last)
	{
		data[(index - 1) / 2] = data[index - 1];
		hole = index - 1;
	}
	data[hole] = data[last];
	data[last] = val;
	pushheap(data, hole);
}

void makeheap(int* data, int size)
{
	for (int i = 1; i < size; i++)
		pushheap(data, i);
}
