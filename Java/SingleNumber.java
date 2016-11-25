public class SingleNumber
{
	public int singleNumber(int[] nums)
	{
		int i,j;
		for(i=0;i<nums.length;i++)
		{
			for(j=0;j<nums.length;j++)
			{
				if(nums[i]==nums[j]&&i!=j)
				{
					break;
				}
			}
			if(j==nums.length)
			{
				return nums[i];
			}
		}
		return 0;
	}
}
