/*
After first elimination, all the numbers left are even numbers.
Divide by 2, we get a continuous new sequence from 1 to n / 2.
For this sequence we start from right to left as the first elimination.
Then the original result should be two times the mirroring result of lastRemaining(n / 2).
*/

int lastRemaining(int n)
{
	return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
}