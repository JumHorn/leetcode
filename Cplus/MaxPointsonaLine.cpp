#include<vector>
#include<algorithm>
#include<map>
#include<map>
#include<unordered_set>
#include<cfloat>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int s=points.size();
        if(s<2)
            return s;
		int res=0;
		for(int i=0;i<(int)points.size()-1;i++)
        {
            map<pair<int,int>,int> data;
            int vertical=0;//该点与x轴垂直的直线上有多少个点
            int slope=0;//同斜率的直线点的个数
            int maxp=0;//最多点数
            int samep=0;//相同点
			for(int j=i+1;j<(int)points.size();j++)
			{
                if(points[i]==points[j])//测试用例的点有重复
                    samep++;
				else if(points[i][0]==points[j][0])
                    vertical++;
				else
				{
					//long double slope=(points[i][1]-points[j][1])*1.0/(points[i][0]-points[j][0]);
                    int a=points[i][1]-points[j][1],b=points[i][0]-points[j][0];
                    int tmp=gcd(a,b);
                    a/=tmp;
                    b/=tmp;
					data[{a,b}]++;
					maxp=max(maxp,data[{a,b}]);
				}
			}
            maxp=max(maxp,vertical)+1+samep;
            res=max(res,maxp);
        }
		return res;
    }

    int gcd(int x,int y)
    {
        if(x==0)
            return y;
        return gcd(y%x,x);
    }
};