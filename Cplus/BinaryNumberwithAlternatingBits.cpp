#include<iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp = ((n>>1)^n);
        while(temp&1==1)
        {
            temp=temp>>1;
        }
        if(temp==0)
        {
            return true;
        }
        return false;
};

// bool hasAlternatingBits(int n) {
//     return !((n ^= n/4) & n-1);
// }
// Xor the number with itself shifted right twice and check whether everything after the leading 1-bit became/stayed 0. Xor is 0 iff the bits are equal, so we get 0-bits iff the pair of leading 1-bit and the 0-bit in front of it are repeated until the end.

//     000101010
//   ^ 000001010
//   = 000100000