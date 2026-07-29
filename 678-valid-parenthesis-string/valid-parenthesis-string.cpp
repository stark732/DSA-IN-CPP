class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for(int i = 0; i< s.size(); i++){
            if(s[i] == '('){
                low +=1;
                high +=1;
            }else if(s[i] == '*'){
                
                low-=1;
                high +=1;
                if (low < 0) low = 0;
                
            }else{
                low-=1;
                high -=1;
                if (low < 0) low = 0;
                if (high < 0) return false;
            }
        }
        
        if(low == 0){
            return true;
        }
        return false;
    }
};