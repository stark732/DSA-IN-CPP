class Solution {
public:
    bool canJump(vector<int>& nums) {
        int is_reachable = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(i> is_reachable){
                return false;
            }else{
                int expect = i+ nums[i];

               is_reachable=  max(is_reachable,expect);
            }
        }
        return true;

    }
};