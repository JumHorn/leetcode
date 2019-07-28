#include<vector>
#include<iostream>
using namespace std;

class NumArray {
private:
	vector<int>& data;
    vector<int> tree;

	void buildTree()
	{
        for(int i=data.size(),j=0;i<2*data.size(); i++,j++)
            tree[i]=data[j];
        for(int i=data.size()-1;i>0;i--)
            tree[i]=tree[i*2]+tree[i*2+1];
	}

public:
    NumArray(vector<int>& nums): data(nums),tree(nums.size()*2){
        buildTree();
    }
    
    void update(int i, int val) {
        i+=data.size();
        tree[i]=val;
        while(i>0)
        {
            int left,right;
            left=right=i;
            if(i%2==0)
                right=i+1;
            else
                left=i-1;
            tree[i/2]=tree[left]+tree[right];
            i/=2;
        }
    }
    
    int sumRange(int i, int j) {
 		i+=data.size();
        j+=data.size();
        int res=0;
        while(i<=j)
        {
            if(i%2==1)
            {
                res+=tree[i];
                i++;
            }
            if(j%2==0)
            {
                res+=tree[j];
                j--;
            }
            i/=2;
            j/=2;
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