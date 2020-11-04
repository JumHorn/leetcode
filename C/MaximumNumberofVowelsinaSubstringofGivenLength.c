
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxVowels(char* s, int k)
{
	int hash[26] = {0};
	char* vowels = "aeiou";
	for (int i = 0; vowels[i]; ++i)
		hash[vowels[i] - 'a'] = 1;
	int res = 0, count = 0;
	for (int i = 0; s[i]; ++i)
	{
		count += hash[s[i] - 'a'];
		if (i >= k)
			count -= hash[s[i - k] - 'a'];
		res = max(res, count);
	}
	return res;
}
