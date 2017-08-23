#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int array[2];
        for(int i=0;i<numbers.size()-1;i++)
        {
            for(int j=i+1;j<numbers.size();j++)
            {
                if(numbers[i]+numbers[j]>target)
                {
                    break;
                }
                if(numbers[i]+numbers[j]==target)
                {
                    array[0]=i+1;
                    array[1]=j+1;
                    // vector<int> ret(array,array+2);
                    return vector<int>({array,array+1});
                }
            }
        }
    }
};

int main()
{}