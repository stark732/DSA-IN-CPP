class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>count(256,0);
        int length = 0, first = 0, last = 0;
        while(last< s.size()){

            while(count[s[last]]){
                count[s[first] ]= 0;
                first++;
            }
            count[s[last]] = 1;
            length = max(length, last-first+1);
            last++;
        }
        return length;

    }
};