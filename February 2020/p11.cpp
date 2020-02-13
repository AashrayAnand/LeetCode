class Solution {
public:
    int maxArea(vector<int>& height) {
        int m = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l < r){
            int cMax = (r - l) * std::min(height[l], height[r]);
            m = std::max(m, cMax);
            if(height[l] > height[r]){
                r--;
            } else {
                l++;
            }
        }
        return m;
    }
};
