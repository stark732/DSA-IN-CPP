class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> freq;

        for(char task : tasks)
            freq[task]++;

        priority_queue<int>pq;

        for(auto x: freq)
            pq.push(x.second);

        int ans = 0;
        while(!pq.empty()){
            int cycle = n+1;
            vector<int>temp;

            while(cycle > 0 && !pq.empty()){
                int count = pq.top();
                pq.pop();
                count --;

                if(count>0)
                    temp.push_back(count);
                
                ans++;
                cycle--;
            }
            for(auto x: temp)
                pq.push(x);

            if(pq.empty())
            break;
            ans+= cycle;
        }   
        return ans;
    }
};