
// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
public:
    int get(int index);
    int length();
};

class Solution {
public:
	int upbinarysearch(int target,MountainArray& m,int lo,int hi)
	{
		while(lo<=hi)
		{
			int mid=lo+(hi-lo)/2;
			int tmp=m.get(mid);
			if(tmp==target)
				return mid;
			if(tmp<target)
				lo=mid+1;
			else
				hi=mid-1;
		}
		return -1;
	}

	int downBinarySearch(int target,MountainArray& m,int lo,int hi)
	{
		while(lo<=hi)
		{
			int mid=lo+(hi-lo)/2;
			int tmp=m.get(mid);
			if(tmp==target)
				return mid;
			if(tmp<target)
				hi=mid-1;
			else
				lo=mid+1;
		}
		return -1;
	}

    int findInMountainArray(int target, MountainArray &mountainArr) {
		int hi=mountainArr.length(),lo=0,peek,len=hi;
	    if(hi==0)
			return -1;	
		hi--;
		while(lo<hi)
		{
			int mid=lo+(hi-lo)/2;
			if(mountainArr.get(mid)<mountainArr.get(mid+1))
				lo=mid+1;
			else
				hi=mid;
		}
		peek=lo;
		int res=upbinarysearch(target,mountainArr,0,peek);
		if(res!=-1)
			return res;
		return downBinarySearch(target,mountainArr,peek+1,len-1);
    }
};
