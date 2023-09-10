using namespace std;

#include <vector>

class Solution {
public:
    vector<int> countBits(int n) { // n=5
        vector<int> dp(n+1, {}); // dp = {0, 0, 0, 0, 0, 0}
        int offset = 1; // multiple of 2
        
        for(int i=1; i<n+1; i++){ // i=1;
            if(offset*2 == i){    // off = 1;
                offset = i;
            }
            dp[i] = (1 + dp[i - offset]); //1+dp[1-1] = 1
        }

        return dp;
    }
};