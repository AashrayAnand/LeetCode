#include <vector>
/* 1304. Find N Unique Integers Sum up to Zero

Given an integer n, return any array containing n unique integers such that they add up to 0.

*/

class Solution {
public:
    vector<int> sumZero(int n) {
        // base cases: n = 0/1, return empty vector
        // or vector only containing 0
        std::vector<int> result;
        if(n == 0){
            return result;
        }
        
        if(n == 1){
            result.push_back(0);
            return result;
        }
        
        // even case: return n/2 values from 
        for(int i = 1; i <= n / 2; i++){
            result.push_back(i);
            result.push_back(-i);
        }
        
        if(n % 2 != 0){
            result.push_back(0);
        }
        
        return result;
    }
};
