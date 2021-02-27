
int getSum(int a, int b)
{
	return (a & b) ? getSum(a ^ b, ((unsigned)a & b) << 1) : (a | b);
}