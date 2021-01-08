
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minFlipsMonoIncr(char *S)
{
	int res = 0;
	for (int one = 0; *S; ++S)
	{
		one += *S - '0';
		//flip all previous ones or flip current 0
		res = min(one, res + 1 - (*S - '0'));
	}
	return res;
}