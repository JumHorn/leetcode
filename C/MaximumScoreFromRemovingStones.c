#define max(a, b) (((a) > (b)) ? (a) : (b))
#define trimax(a, b, c) (max(max(a, b), c)) //the maximum of a,b,c

int maximumScore(int a, int b, int c)
{
	int maxval = trimax(a, b, c);
	int sum = a + b + c;
	if (maxval > sum - maxval)
		return sum - maxval;
	return sum / 2;
}