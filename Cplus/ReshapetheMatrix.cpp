#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //这里加空格，避免误认为>>符号
    vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
        if(nums.size()==0||nums[0].size()*nums.size()!=r*c)
        {
            return nums;
        }
        int i,j,m,n;
        vector<vector<int> > newnums(r);//初始化
        //newnums.resize(r);   //同上
        cout<<nums.size()<<","<<nums[0].size()<<endl;
        for(i=0;i<r;i++)
        {
            newnums[i].resize(c);
            //newnums.push_back(new vector<int>);
            for(j=0;j<c;j++)
            {
                //行列转换
                m=(i*c+j)/nums[0].size();
                n=(i*c+j)%nums[0].size();
                cout<<i*c+j<<":"<<m<<","<<n<<endl;                
                // newnums[i].push_back(nums[m][n]);
                newnums[i][j]=nums[m][n];
            }
        }
        return newnums;
    }
};

void print(vector<vector<int> > vec)
{
    for(int i=0;i<vec.size();i++) 
    {
        for(int j=0;j<vec[0].size();j++) 
            cout<<vec[i][j]<<","; 
        cout<<endl;
    }
}

int main()
{
    vector<vector<int> >  array(2); 
    for(int i=0;i<2;i++) 
    {
        array[i].resize(3);
        for(int j=0;j<3;j++) 
            array[i][j]=(i+1)*(j+1); 
    }
    print(array);
    Solution sol;
    print(sol.matrixReshape(array,3,2));
    return 0;
}