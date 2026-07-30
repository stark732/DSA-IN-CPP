class Solution {
public:
    int jump(vector<int>& nums) {
        int ans =0;
        int current = 0;
        int is_reachable =0;
        
        int n = nums.size();

        if(n==1)
            return 0;

        for(int i = 0; i< n-1; i++){
            is_reachable = max(is_reachable, i+nums[i] );

            if( i== current){
                ans++;
                current  = is_reachable;
            }
        }
        return ans;
    }
};