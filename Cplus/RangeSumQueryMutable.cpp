#include<vector>
using namespace std;

class NumArray {
private:
	vector<int> tree;
	vector<int> v;
public:
    NumArray(vector<int>& nums):tree(nums.size()+1),v(nums.size()) {
        for(int i=0;i<(int)nums.size();i++)
			update(i,nums[i]);
    }
    
    void update(int i, int val) {
        int delta=val-v[i];
        v[i]=val;
		i++;
		while(i<(int)tree.size())
		{
			tree[i]+=delta;
			i+=i&(-i);
		}
    }
    
    int sumRange(int i, int j) {
        return query(j)-query(i-1);
    }

private:
	int query(int i)
	{
		int res=0;
		i++;
		while(i!=0)
		{
			res+=tree[i];
			i-=i&(-i);
		}
		return res;
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */