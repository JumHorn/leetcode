#include<string>
#include<vector>
#include<unordered_set>
#include<cmath>
using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        unordered_set<string> visited;
        string node(n-1,'0'),res;
        dfs(node,n,k,visited,res);
        return res+node;
    }

    void dfs(string node,int n,int k,unordered_set<string>& visited,string& res)
    {
        for(int i=0;i<k;i++)
        {
            string tmp=node+to_string(i);
            if(visited.find(tmp)==visited.end())
            {
                visited.insert(tmp);
                dfs(tmp.substr(1),n,k,visited,res);
                res+=to_string(i);
            }
        }
    }
};