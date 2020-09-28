#include <stdbool.h>
#include <string.h>

bool makesquare(int *nums, int numsSize)
{
	int N = numsSize, perimeter = 0, all = (1 << N) - 1;
	for (int i = 0; i < numsSize; ++i)
		perimeter += nums[i];
	if (perimeter % 4)
		return false;
	int sideLen = perimeter / 4;
	// bitmask which sum equal to one sideLen
	int oneSide[1 << N], oneSideSize = 0;
	// bitmask which sum equal to two sideLen
	bool twoSides[1 << N];
	memset(twoSides, 0, sizeof(twoSides));

	for (int mask = 1; mask < 1 << N; ++mask)
	{
		int subsetSum = 0;
		// calculate the sum of this subset
		for (int i = 0; i < N; ++i)
		{
			if (mask & (1 << i))
				subsetSum += nums[i];
		}
		if (subsetSum == sideLen)
		{
			for (int i = 0; i < oneSideSize; ++i)
			{
				// if this mask and previous are mutually exclusive
				if ((oneSide[i] & mask) == 0)
				{
					// then they form a valid half subset whose sum is 2 * sideLen,
					// that can be further partitioned into two equal subsets (usedMask and mask)
					int twosides = oneSide[i] | mask;
					twoSides[twosides] = true;
					// if in the past we concluded that the other half is also a valid
					// half subset, DONE!
					if (twoSides[all ^ twosides])
						return true;
				}
			}
			oneSide[oneSideSize++] = mask;
		}
	}
	return false;
}