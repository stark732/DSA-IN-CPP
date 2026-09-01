class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
       /* string ans = strs[0];

        for(int i = 1; i< strs.size(); i++){

            int j = 0;

            while(j<ans.length() &&
                j< strs[i].length() &&
                ans[j] == strs[i][j]){

                j++;
            }
            ans = ans.substr(0,j);

            if(ans.empty()) return "";
        }
    return ans;
    }*/

    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs[strs.size()-1];

    int i = 0;

    while(i<first.size() && i<last.size()&& first[i] == last[i]){
            i++;
    }
    return first.substr(0, i);
    }
};