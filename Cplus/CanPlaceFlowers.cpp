#include<iostream>
#include<vector>
using namespace std;

class solution
{
    public:
        bool canPlaceFlowers(vector<int>& flowerbed,int n);
};

bool solution::canPlaceFlowers(vector<int>& flowerbed,int n)
{
    int i=0,num=0,flag=1;
    if(n==0)
    {
        return true;
    }
    for(i=0;i<flowerbed.size();i++)
    {
        if(flag==1)
        {
            //cout<<"i "<<i<<endl;  
            //cout<<"size "<<flowerbed.size()<<endl;
            //cout<<"flower "<<flowerbed[i]<<endl;         
            if(flowerbed[i]==1)
            {
                flag=0;
                continue;
            }
            if(i+1<flowerbed.size()&&flowerbed[i+1]==0)
            {               
                flag=0;
                cout<<"start "<<i<<":"<<num+1<<endl;
                if(++num>=n)
                {
                    return true;
                }
            }
            if(i==flowerbed.size()-1&&flowerbed[i]==0)
            {
                cout<<"end "<<i<<":"<<num+1<<endl;  
                if(++num>=n)
                {                  
                    return true;
                }
            }
        }
        else
        {
            if(flowerbed[i]==0)
            {
                flag=1;
            }
        }
    }
    return false;
}

int main()
{
    int A[5]={0,0,1,0,0};
    vector<int> flower(&A[0],&A[5]);//初始化下标需要注意，右侧是开区间
    for(vector<int>::const_iterator iterator=flower.begin();iterator!=flower.end();iterator++)
    {
        cout<<*iterator<<endl;
    }
    cout<<"----------------"<<endl;
    cout<<flower.size()<<endl;
    solution sol;
    sol.canPlaceFlowers(flower,2);
    //cout<<sol.canPlaceFlowers(flower,2)<<endl;
    return 0;
}