#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

class Solution {
public:
    vector<vector<int> > imageSmoother(vector<vector<int> >& M) {
        if(M.size()==0||M[0].size()==0)
        {
            return M;
        }
        vector<vector<int> > N(M);
        //print(N);
        for(int i=0;i<M.size();i++)
        {
            M[i].insert(M[i].begin(),-1);
            M[i].push_back(-1);
        }
        int *p1 = new int[M[0].size()];
        //cout<< M[0].size() <<endl;
        
        for(int i=0;i<M[0].size();i++)
        {
            p1[i]=-1;
        }
        vector<int> v1(p1,p1+M[0].size());
        M.insert(M.begin(),v1);
        M.push_back(v1);  
        print(M);
        int p=0,q=0;
        for(int i=1;i<M.size()-1;i++)
        {
            for(int j=1;j<M[i].size()-1;j++)
            {
                p=0;
                q=0;
                for(int m=-1;m<=1;m++)
                {
                    for(int n=-1;n<=1;n++)
                    {
                        if(M[i+m][j+n]==-1)q++;
                        else p+=M[i+m][j+n];
                    }
                }
                //cout<<q<<endl;
                N[i-1][j-1] = p/(9-q);
            }
        }
        
        return N;
    }
};

int main()
{}