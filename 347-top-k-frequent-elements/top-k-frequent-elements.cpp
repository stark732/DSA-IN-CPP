class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<int>ans;

        priority_queue<pair<int, int>> pq;

        for(auto x : freq){
            pq.push({x.second, x.first});
        }
        for(int i= 1; i<=k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};