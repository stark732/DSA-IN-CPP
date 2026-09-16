class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0]; 
        int maxproduct = nums[0];
        int minproduct = nums[0];
        for(int i = 1; i<nums.size(); i++){
            
            int oldMax = maxproduct;
            int oldMin = minproduct;

            maxproduct = max({
                nums[i],
                oldMax * nums[i],
                oldMin * nums[i]
            });

            minproduct = min({
                nums[i],
                oldMax * nums[i],
                oldMin * nums[i]
            });
             ans = max(ans, maxproduct);
        }
        return ans;
    }
};