class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        int value = 0;

        for ( int num : nums){
            value = value ^ num;

        }
        return value;
    }
};