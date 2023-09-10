using namespace std;

#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        long long int count = 0;
        while(n > 0){
            if(n & 1 == 1){
                count++;
            }
            n = n >> 1;
        }
        return count;
    }
};