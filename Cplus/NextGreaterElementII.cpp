#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> res(nums.size(),-1);
		for(int i=0;i<nums.size();i++)
		{
			int j;
			for(j=1;j<nums.size();j++)
			{
				int index=(i+j)%nums.size();
				if(nums[i]<nums[index])
				{
					res[i]=nums[index];
					break;
				}
			}
		}
		return res;
    }
};

//public class Solution {
//
//    public int[] nextGreaterElements(int[] nums) {
//        int[] res = new int[nums.length];
//        Stack<Integer> stack = new Stack<>();
//        for (int i = 2 * nums.length - 1; i >= 0; --i) {
//            while (!stack.empty() && nums[stack.peek()] <= nums[i % nums.length]) {
//                stack.pop();
//            }
//            res[i % nums.length] = stack.empty() ? -1 : nums[stack.peek()];
//            stack.push(i % nums.length);
//        }
//        return res;
//    }
//}
