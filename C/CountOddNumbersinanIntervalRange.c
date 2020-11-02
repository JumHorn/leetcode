
/*
the count of odd numbers between 1 and low - 1 is low / 2
the count of odd numbers between 1 and high is (high + 1 ) / 2
*/
int countOdds(int low, int high)
{
	return (high + 1) / 2 - low / 2;
}
