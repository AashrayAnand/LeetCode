class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return vector<int> {-1, -1};
        }
        
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        int m = (l + r) / 2;
        
        while(l <= r){
            m = (l + r + 1) / 2;
            if(nums[m] == target){
                return sweepArr(nums, m);
            }
            if(nums[l] == target){
                return sweepArr(nums, l);
            }
            if(nums[r] == target){
                return sweepArr(nums, r);
            }
            l++;
            r--;
        }
        
        return vector<int> {-1, -1};
    }
    
    vector<int> sweepArr(vector<int>& nums, int idx){
        int target = nums[idx];
        vector<int> res;
        int l = idx;
        int r = idx;
        while(l - 1 >= 0 && nums[l - 1] == target){
            l--;
        }
        res.push_back(l);
        while(r + 1 < nums.size() && nums[r + 1] == target){
            r++;
        }
        res.push_back(r);
        return res;
    }
};
