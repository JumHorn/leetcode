
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minFlipsMonoIncr(char* S)
{
	int one = 0, res = 0;
	while (*S)
	{
		one += *S - '0';
		res = min(one, res + 1 - (*S - '0'));  //flip all previous ones or flip current 0
		++S;
	}
	return res;
}
