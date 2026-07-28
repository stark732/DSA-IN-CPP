class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
        return false;

        unordered_map<int, int> freq;
        for(int x : hand)
            freq[x]++;

        priority_queue<int , vector<int>, greater<int>>pq;

        for(auto x:freq)
            pq.push(x.first);

        while(!pq.empty()){
            int start = pq.top();

            for(int i = 0; i<groupSize; i++){
                int next = start +i;

                if(freq[next] == 0)
                    return false;

                freq[next]--;

                if(freq[next] == 0){
                    if(next != pq.top())
                    return false;
                    pq.pop();
                }
            }
        }
        return true;

    }
};