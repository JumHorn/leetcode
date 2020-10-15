#include <stdbool.h>

bool validateStackSequences(int *pushed, int pushedSize, int *popped, int poppedSize)
{
	int top = -1, poppedIdx = 0;
	for (int k = 0; k < pushedSize; ++k)
	{
		pushed[++top] = pushed[k];
		while (top != -1 && popped[poppedIdx] == pushed[top])
		{
			++poppedIdx;
			--top;
		}
	}
	return top == -1;
}