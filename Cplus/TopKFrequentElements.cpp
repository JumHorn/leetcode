#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
	    map<int,int> dic;
		for(int i=0;i<nums.size();i++)
		{
			dic[nums[i]]++;
		}		
		for(int i=0;i<k;i++)
		{
			res.push_back(findmax(dic));
		}
		return res;
    }
	int findmax(map<int,int>& dic)
	{
		int minval=0;
		int res;
		map<int,int>::iterator it;
		for(map<int,int>::iterator iter=dic.begin();iter!=dic.end();iter++)
		{
			if(iter->second>minval)
			{
				minval=iter->second;
				res=iter->first;
				it=iter;
			}
		}
		dic.erase(it);
		return res;
	}
};

//java solution
//开辟一个大的数组能存储最大的value值的下标
//将value作为下标，key作为值存储到数组中，再从数组中反向查找k个值

// public List<Integer> topKFrequent(int[] nums, int k) {

// 	List<Integer>[] bucket = new List[nums.length + 1];
// 	Map<Integer, Integer> frequencyMap = new HashMap<Integer, Integer>();

// 	for (int n : nums) {
// 		frequencyMap.put(n, frequencyMap.getOrDefault(n, 0) + 1);
// 	}

// 	for (int key : frequencyMap.keySet()) {
// 		int frequency = frequencyMap.get(key);
// 		if (bucket[frequency] == null) {
// 			bucket[frequency] = new ArrayList<>();
// 		}
// 		bucket[frequency].add(key);
// 	}

// 	List<Integer> res = new ArrayList<>();

// 	for (int pos = bucket.length - 1; pos >= 0 && res.size() < k; pos--) {
// 		if (bucket[pos] != null) {
// 			res.addAll(bucket[pos]);
// 		}
// 	}
// 	return res;
// }
