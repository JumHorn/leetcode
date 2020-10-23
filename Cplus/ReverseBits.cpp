#include <cstdint>

/*
The algorithm is documented as "reverse the bits in a byte with 3 operations"
 on the online book called Bit Twiddling Hacks by Sean Eron Anderson
*/

class Solution
{
public:
	uint32_t reverseBits(uint32_t n)
	{
		uint32_t res = 0;
		for (int i = 0; i < 4; ++i)
			res = (res << 8) + reverseByte((n >> (i * 8)) & 0xff);
		return res;
	}

	uint32_t reverseByte(uint32_t n)
	{
		return (n * 0x0202020202 & 0x010884422010) % 1023;
	}
};