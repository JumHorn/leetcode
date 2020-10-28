
#define max(a, b) (((a) > (b)) ? (a) : (b))

int findTheLongestSubstring(char* s)
{
	int vowels[26] = {0}, hash[64] = {0};  //{mask,index}
	vowels['a' - 'a'] = 1;
	vowels['e' - 'a'] = 2;
	vowels['i' - 'a'] = 3;
	vowels['o' - 'a'] = 4;
	vowels['u' - 'a'] = 5;
	for (int i = 0; i < 64; ++i)
		hash[i] = -2;
	hash[0] = -1;
	int mask = 0, res = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (vowels[s[i] - 'a'] != 0)
		{
			mask ^= 1 << vowels[s[i] - 'a'];
			if (hash[mask] == -2)
				hash[mask] = i;
		}
		res = max(res, i - hash[mask]);
	}
	return res;
}
