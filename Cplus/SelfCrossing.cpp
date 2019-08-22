#include<vector>
using namespace std;

// math period problem
// same problem
// Count The Repetitions

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
		if(x.size()<4)
			return false;
		for(int i=3;i<(int)x.size();i++)
		{
            if(x[i]>=x[i-2]&&x[i-1]<=x[i-3])
                return true;
            if(i>3)
                if(x[i-1]==x[i-3]&&x[i]+x[i-4]>=x[i-2])
                    return true;
            if(i>4)
                if(x[i-2]>=x[i-4]&&x[i-1]<=x[i-3]&&x[i-1]>=x[i-3]-x[i-5]&&x[i]>=x[i-2]-x[i-4])
                    return true;
		}
		return false;
    }
};

