
char* shiftingLetters(char* S, int* shifts, int shiftsSize)
{
	for (int i = shiftsSize - 2; i >= 0; --i)
		shifts[i] = shifts[i] % 26 + shifts[i + 1] % 26;
	for (int i = 0; i < shiftsSize; ++i)
		S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
	return S;
}
