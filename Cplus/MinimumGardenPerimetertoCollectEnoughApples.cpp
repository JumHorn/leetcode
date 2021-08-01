class Solution
{
public:
	long long minimumPerimeter(long long neededApples)
	{
		long long d = 1, sum = 0;
		for (; sum < neededApples; ++d)
		{
			sum += (((d + 1) + (d + d)) * d - 2 * d) * 4; //四个象限数据
			sum += d * 4;								  //坐标轴上数据
		}
		return (d - 1) * 8;
	}
};