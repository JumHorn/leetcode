#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class solution 
{
    public:
        string reverseWords(string s)
        {
            string::iterator iter = s.begin();
            string::iterator temp = s.begin();
            while(iter!=s.end())
            {
                if(*iter==' ')
                {
                    reverse(temp,iter);
                    temp=iter+1;
                }
                iter++;
            }
            reverse(temp,iter);
            return s;
        }
};

int main()
{
    solution sol;
    cout<<sol.reverseWords("testa")<<endl;
    return 0;
}