class Solution {
public:
    int balancedStringSplit(string s) {
        int sum = 0;
        int balance = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'L'){
                balance--;
            } else {
                balance++;
            }
            sum = balance == 0 ? sum + 1: sum;
        }
        return sum;
    }
};
