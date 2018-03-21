#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int m1,n1,m2,n2;
    string complexNumberMultiply(string a, string b) {
        int m,n;
        string result;
        decompose(a,m1,n1);
        decompose(b,m2,n2);
        m=m1*m2-n1*n2;
        n=m1*n2+m2*n1;
        result=to_string(m)+"+"+to_string(n)+"i";
        return result;
    }

    void decompose(string c,int &m,int &n)
    {
        string left;
        size_t sz;
        m=stoi(c,&sz);
        left=c.substr(sz+1);
        n=stoi(left,&sz);
    }
};