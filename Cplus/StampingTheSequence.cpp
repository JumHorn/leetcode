#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
		int M=stamp.length();        
		vector<int> res,last;
		if(target.find(stamp)==string::npos)
			return res;
		for(int i=0;i<M;i++)
			for(int j=0;j<=i;j++)
			{
				string newstamp=string(j,'?')+stamp.substr(j,M-i)+string(i-j,'?');
				auto index=target.find(newstamp);
				if(index!=string::npos)
				{
					res.push_back(index);
					fill(target.begin()+index,target.begin()+index+M,'?');
					i=-1;
				}
			}
		if(target.find_first_not_of('?')==string::npos)
		{
			reverse(res.begin(),res.end());
			return res;
		}
		return vector<int>();
    }
};