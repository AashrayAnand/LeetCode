class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        help(nums, res, 0, nums.size());
        return res;
    }
    
    void help(vector<int>& in, vector<int>& out, int start, int end){
        // when only 2 elements, multiply each index
        // by number in other index
        if(start < end - 1){
            // partition index for computing half products
            // and executing recursive subproblems
            int partition = (start + end + 1) / 2;
            std::cout << start << " " << partition << " " << end << std::endl;
            int prod1 = prod(in, start, partition);
            int prod2 = prod(in, partition, end);
            for(int i = start; i < partition; i++){
                out[i] *= prod2;
            }
            for(int i = partition; i < end; i++){
                out[i] *= prod1;
            }
            help(in, out, start, partition);
            help(in, out, partition, end);
        }
    }
    
    int prod(vector<int>& nums, int start, int end){
        int prod = 1;
        for(int i = start; i < end; i++){
            prod *= nums[i];
        }
        return prod;
    }
};
