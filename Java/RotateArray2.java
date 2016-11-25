public class RotateArray2
{
	public void rotate(int[] nums,int k)
	{
		int[] nums_copy = new int[nums.length];
		int i,j;
		k=k%nums.length;
		if(k>nums.length)return ;
		for(i=0;i<nums.length-k;i++)
		{
			nums_copy[i+k]=nums[i];
		}
		for(i=nums.length-k;i<nums.length;i++)
		{
			nums[i-nums.length+k]=nums[i];
		}
		for(i=k;i<nums.length;i++)
		{
			nums[i]=nums_copy[i];
		}
	}
}
