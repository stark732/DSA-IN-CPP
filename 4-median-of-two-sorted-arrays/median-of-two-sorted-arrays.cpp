class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        int n1 = nums1.size();
        int n2 = nums2.size();

        int mid = (n1+n2)/2;
        int left = 0;
        int right = 0;
        int prev = 0;
        int curr = 0;


        for(int i =0; i <= mid; i++){
            prev = curr;

            if( left < n1 && (right >= n2 || nums1[left] < nums2[right])){
                curr = nums1[left];
                left++;
            }else{
                curr = nums2[right];
                right++;
            }
        }
        if((n1+n2)%2 == 0){
            return (prev+curr)/2.0;
        }
        return curr;
        */

        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0;
        int high =n1;

        while( low <= high){
            int part1 = (low + high)/2;
            int part2 = (n1 + n2 +1) / 2 - part1;

            int left1 = part1 == 0 ? INT_MIN : nums1[part1-1];
            int right1 = part1 == n1 ? INT_MAX : nums1[part1];

            int left2 = part2 == 0 ? INT_MIN : nums2[part2 -1];
            int right2 = part2 == n2 ? INT_MAX : nums2[part2];

            if(left1 <= right2 && left2 <= right1){
                if((n1+n2)%2 == 1){
                    return max(left1, left2);
                }

                return (max(left1,left2) + min(right1, right2))/2.0;
            }

            if( left1 > right2){
                high = part1 -1;
            }else{
                low = part1+1;
            }
        }
        return 0.0;
    }
};