class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>ans;

        for(int i =0; i < nums.size(); i++){
            int required = target - nums[i];

            if(ans.find(required) != ans.end()){
                return {ans[required], i};
            }
        
            ans[nums[i]] = i;

        }
    return {};
    }
};