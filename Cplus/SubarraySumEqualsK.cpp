#include<vector>
using namespace std;
/*
------------------------->
|    Sum(i,j)=Sum(i-1,j)-A[i];
|
|
|
|
|
|
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		vector<int> dp(nums.size());
		int res=0,sum=0;
		for(int i=0;i<nums.size();i++)
		{
			sum+=nums[i];
			dp[i]=sum;
			if(sum==k)
				res++;
		}
		for(int i=1;i<nums.size();i++)
        {
			for(int j=0;j<i;j++)
			{
				dp[i]=dp[i]-nums[j];
				if(dp[i]==k)
					res++;
			}
        }
		return res;
	}
};


//public class Solution {
//    public int subarraySum(int[] nums, int k) {
//        int count = 0, sum = 0;
//        HashMap < Integer, Integer > map = new HashMap < > ();
//        map.put(0, 1);
//        for (int i = 0; i < nums.length; i++) {
//            sum += nums[i];
//            if (map.containsKey(sum - k))
//                count += map.get(sum - k);
//            map.put(sum, map.getOrDefault(sum, 0) + 1);
//        }
//        return count;
//    }
//}
