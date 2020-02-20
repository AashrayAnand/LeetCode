class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for(int i = 0; i < nums.size(); i++){
            int c = nums[i - 1];
            
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                if(k < nums.size() - 1 && nums[k] == nums[k + 1]){
                    k--;
                    continue;
                }
                
                if(nums[i] + nums[j] + nums[k] < 0){
                    j++;
                } else if(nums[i] + nums[j] + nums[k] > 0){
                    k--;
                } else {
                    res.push_back(vector<int> {nums[i], nums[j], nums[k]});
                    j++;
                    k--; 
                }
            }
        }
        return res;
    }
};
