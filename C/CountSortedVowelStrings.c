
/*
combination number C(n + 4, 4)
*/

int countVowelStrings(int n)
{
	return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
}